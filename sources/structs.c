/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 16:06:21 by owhearn       #+#    #+#                 */
/*   Updated: 2025/06/10 11:06:02 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	set_forks(t_philo *philo)
{


	return (true);
}

bool	fill_philosophers(t_data *data, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < data->philonbr)
	{
		philo[i].data = data;
		if (set_mutex(philo[i].meal_lock));
		philo[i].fork1 = set_mutex(data->forks);//cut this out, move it to data setup
		if (!philo[i].meal_lock || !philo[i].fork1)
			return (false);
		philo[i].dead = false;
		philo[i].last_meal = 0;
		philo[i].num = (i + 1);
		philo[i].times_eaten = 0;
		i++;
	}
	
	return (true);
}

t_philo	*configure_philos(t_data *data)
{
	t_philo	*new_arr;
	int		i;

	i = 0;
	new_arr = (t_philo *)malloc(sizeof(t_philo) * (data->philonbr + 1));
	if (!new_arr)
		return (NULL);
	if (fill_philosphers(data, new_arr) == false)
		return (NULL);/*replace NULL with free function*/
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
	new->print = 0;
	new->infinite = true;
	new->finish = false;
	return (new);
}
