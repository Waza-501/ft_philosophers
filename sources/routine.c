/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 15:01:05 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/17 16:30:43 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(t_data *data, size_t delay)
{
	time_t	target;

	target = get_current_time() + delay;
	while (get_current_time() < target)
	{
		if (check_status(data) == true)
			break ;
		usleep(500);
	}

}

void	ft_eat(t_philo *philo, t_data *data)
{
	
}

void	*philo_routine(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	if (philo->data->infinite == false && philo->data->input->meal_target == 0)
		return ;
	delay_start(philo->data);
	if (philo->id % 2)
		ft_sleep(philo->data, philo->data->input->time_sleep);
	while (true)
	{
		print_msg(philo, SLEEP);
		ft_sleep(philo->data, philo->data->input->time_sleep);
	}
	return ;
}
