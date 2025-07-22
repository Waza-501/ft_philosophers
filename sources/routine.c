/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 15:01:05 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/22 16:38:06 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_delay(t_data *data, size_t delay)
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

void	ft_think(t_philo *philo, t_data *data)
{
	(void)data;
	print_status(philo, THINK);
}

void	ft_sleep(t_philo *philo, t_data *data)
{
	print_status(philo, SLEEP);
	ft_delay(data, data->input->time_sleep);
}

void	ft_eat(t_philo *philo, t_data *data)
{
	/*replace exits with actual end conditions*/
	if (grab_forks(philo, data) == false)
		exit(1);
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal_lock);
	ft_delay(data, data->input->time_eat);
	pthread_mutex_lock(&philo->meal_lock);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	if (drop_forks(philo, data) == false)
		exit(1);
}

void	*philo_routine(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	if (philo->data->infinite == false && philo->data->input->meal_target == 0)
		return (NULL);
	delay_start(philo->data);
	if (philo->id % 2)
		/*replace this with thinking*/
		ft_delay(philo->data, philo->data->input->time_sleep);
	while (true)
	{
		ft_eat(philo, philo->data);
		ft_sleep(philo, philo->data);
		if (check_status(philo->data) == true)
			break ;
		ft_think(philo, philo->data);
	}
	return (NULL);
}
