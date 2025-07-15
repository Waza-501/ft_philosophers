/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 14:49:27 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/15 16:51:50 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*all of this needs to be redone*/
void	clean_philos(t_philo *philo, int target)
{
	int	i;

	i = 0;
	while (i < target)
	{
		if (philo[i].meal_lock)
			clean_mutex(philo[i].meal_lock);
		i++;
	}
	free(philo);
}

void	clean_data(t_data *data)
{
	clean_mutex(data->print);
	clean_mutex(data->forks);
}

void	clean_mutex(pthread_mutex_t	*target)
{
	pthread_mutex_destroy(target);
	free(target);
}
