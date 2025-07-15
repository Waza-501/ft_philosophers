/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_philo.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 14:44:25 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/15 16:52:47 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	fill_philosophers(t_data *data, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < data->input->nbr)
	{
		philo[i].data = data;
		philo[i].id = (i + 1);
		philo[i].times_eaten = 0;
		philo[i].last_meal = data->start;
		if (pthread_mutex_init(philo[i].meal_lock, NULL))
			return (false);
		i++;
	}
	return (true);
}

t_philo	*init_philos(t_data *data)
{
	t_philo	*new;
	int		i;

	i = 0;
	new = (t_philo *)malloc(sizeof(t_philo) * (data->input->nbr + 1));
	if (!new)
		return (NULL);
	if (fill_philosphers(data, new) == false)
		return (clean_philos(new, data->input->nbr));
	return (new);
}
