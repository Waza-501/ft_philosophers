/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_philo.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 14:44:25 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/14 17:50:36 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	fill_philosophers(t_data *data, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < data->input->philonbr)
	{
		philo[i].data = data;
		if (set_mutex(philo[i].meal_lock));
			philo[i].fork1 = set_mutex(data->forks);//cut this out, move it to data setup
		if (!philo[i].meal_lock || !philo[i].fork1)
			return (false);
		philo[i].dead = false;
		philo[i].last_meal = 0;
		philo[i].id = (i + 1);
		philo[i].times_eaten = 0;
		i++;
	}
	
	return (true);
}

t_philo	*init_philos(t_data *data)
{
	t_philo	*new;
	int		i;

	i = 0;
	new = (t_philo *)malloc(sizeof(t_philo) * (data->input->philonbr + 1));
	if (!new)
		return (NULL);
	if (fill_philosphers(data, new) == false)
		return (NULL);/*replace NULL with free function*/
	return (new);
}
