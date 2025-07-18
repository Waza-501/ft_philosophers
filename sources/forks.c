/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 13:15:19 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/17 16:39:16 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	drop_forks(t_philo *philo, t_data *data)
{
	if (pthread_mutex_unlock(philo->fork1) != 0)
		return (false);
	if (pthread_mutex_unlock(philo->fork2) != 0)
		return (false);
	return (true);
}

bool	grab_forks(t_philo *philo, t_data *data)
{
	if (pthread_mutex_lock(philo->fork1) != 0)
		return (false);
	if (pthread_mutex_lock(philo->fork2) != 0)
		return (false);
	return (true);
}

pthread_mutex_t	*create_forks(int nbr)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (nbr + 1));
	if (!forks)
		return (NULL);
	while (i < nbr)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			clean_multimutex(forks, i);
			return (NULL);
		}
		i++;
	}
	printf("created %i forks\n", i);
	return (forks);
}
