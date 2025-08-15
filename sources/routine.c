/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 15:01:05 by owhearn       #+#    #+#                 */
/*   Updated: 2025/08/15 17:37:02 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_think(t_philo *philo)
{
	if (philo->data->input->nbr % 2)
		ft_delay(philo->data, (philo->data->input->time_eat / 2));
	print_status(philo, THINK);
}

void	ft_sleep(t_philo *philo, t_data *data)
{
	print_status(philo, SLEEP);
	ft_delay(data, data->input->time_sleep);
}

/*replace exits with actual end conditions*/
void	ft_eat(t_philo *philo, t_data *data)
{
	grab_forks(philo);
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal_lock);
	ft_delay(data, data->input->time_eat);
	pthread_mutex_lock(&philo->meal_lock);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	drop_forks(philo);
}

void	*philo_routine(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	if (philo->data->infinite == false && philo->data->input->meal_target == 0)
		return (NULL);
	delay_start(philo->data);
	if (check_status(philo->data) == true)
		return (NULL);
	if (philo->id % 2)
		ft_delay(philo->data, (philo->data->input->time_eat / 2));
	while (true)
	{
		ft_eat(philo, philo->data);
		ft_sleep(philo, philo->data);
		if (check_status(philo->data) == true)
			break ;
		ft_think(philo);
	}
	return (NULL);
}
