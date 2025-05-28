/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 16:06:21 by owhearn       #+#    #+#                 */
/*   Updated: 2025/05/28 13:48:58 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	fill_philosphers(t_data *data, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < data->philonbr)
	{
		philo[i].data = data;
		philo[i].dead = false;
		philo[i].last_meal = 0;
		philo[i].num = (i + 1);
		philo[i].times_eaten = 0;
		i++;
	}
	return (true);
}

t_philo	*create_philosophers(t_data *data)
{
	t_philo	*new_arr;

	new_arr = (t_philo *)malloc(sizeof(t_philo) * (data->philonbr + 1));
	if (!new_arr)
		return (NULL);
	return (new_arr);
}

void	*prepare_data(void)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->philonbr = 0;
	new->time_die = 0;
	new->time_eat = 0;
	new->time_sleep = 0;
	new->meal_target = 0;
	new->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	new->forks = NULL;
	if (!new->print)
		return (NULL);
	new->infinite = true;
	new->finish = false;
	return (new);
}
