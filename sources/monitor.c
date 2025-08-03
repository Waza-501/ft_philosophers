/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/19 16:45:51 by owen          #+#    #+#                 */
/*   Updated: 2025/07/30 17:52:42 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	target = false;
	(void)data;
	while (idx < philo->data->input->nbr)
	{
		pthread_mutex_lock(&philo[idx].meal_lock);
		if (starve_check(&philo[idx], philo->data->input) == true)
		{
			print_status(&philo[idx], DEATH);
			set_finish(philo->data);
			pthread_mutex_unlock(&philo[idx].meal_lock);
			return (true);
		}
		target = meal_target(&philo[idx], philo->data->input);
		pthread_mutex_unlock(&philo[idx].meal_lock);
		idx++;
	}
	if (target == true)
	{
		print_status(philo, FINISH);
		set_finish(philo->data);
	}
	return (false);
}

void	*monitor(void *input)
{
	t_philo		*philo;

	philo = (t_philo *)input;
	delay_start(philo->data);
	while (true)
	{
		if (cycle_array(philo, philo->data) == true)
			return (NULL);
		usleep(1000);
	}
}
