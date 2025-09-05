/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/19 16:45:51 by owen          #+#    #+#                 */
/*   Updated: 2025/09/05 15:55:42 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	check_status(t_data *data)
{
	bool	status;

	pthread_mutex_lock(&data->status);
	status = data->finish;
	pthread_mutex_unlock(&data->status);
	return (status);
}

bool	starve_check(t_philo *philo, t_input *input)
{
	if ((get_current_time() - philo->last_meal) > input->time_die)
		return (true);
	return (false);
}

bool	meal_target(t_philo *philo, t_input *input)
{
	if (philo->data->infinite == true)
		return (false);
	if (philo->times_eaten >= input->meal_target)
		return (true);
	return (false);
}

bool	cycle_array(t_philo *philo, t_data *data)
{
	int		idx;
	bool	target;

	idx = 0;
	target = true;
	while (idx < philo->data->input->nbr)
	{
		pthread_mutex_lock(&philo[idx].meal_lock);
		if (starve_check(&philo[idx], philo->data->input) == true)
		{
			set_finish(data);
			print_status(&philo[idx], DEATH);
			pthread_mutex_unlock(&philo[idx].meal_lock);
			return (true);
		}
		if (meal_target(&philo[idx], philo->data->input) == false)
			target = false;
		pthread_mutex_unlock(&philo[idx].meal_lock);
		idx++;
	}
	if (target == true && data->infinite == false)
		set_finish(data);
	return (false);
}

void	*monitor(void *input)
{
	t_philo		*philo;

	philo = (t_philo *)input;
	delay_start(philo->data);
	while (true && check_status(philo->data) == false)
	{
		if (cycle_array(philo, philo->data) == true)
			return (NULL);
	}
	return (NULL);
}
