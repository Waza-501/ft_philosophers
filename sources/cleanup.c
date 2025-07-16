/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 14:49:27 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/16 14:38:59 by owhearn       ########   odam.nl         */
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
		clean_mutex(&philo[i].meal_lock);
		i++;
	}
	free(philo);
}

void	clean_multimutex(pthread_mutex_t *target, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		pthread_mutex_destroy(&target[i]);
		i++;
	}
	free (target);
}

void	clean_data(t_data *data)
{
	clean_mutex(&data->print);
	clean_multimutex(data->forks, data->input->nbr);
	free(data->threads);
	free(data->input);
	free(data);
}

void	clean_mutex(pthread_mutex_t	*target)
{
	pthread_mutex_destroy(target);
}
