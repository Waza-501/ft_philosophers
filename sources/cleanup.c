/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 14:49:27 by owhearn       #+#    #+#                 */
/*   Updated: 2025/09/10 18:59:05 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	err_exit(t_data *data, int num, t_philo *philo)
{
	if (join_threads(data, num, true) == false)
		exit (1);
	clean_philos(philo, data->input->nbr);
	free(philo);
	return (EXIT_BAD);
}

void	clean_philos(t_philo *philo, int target)
{
	int	i;

	i = 0;
	while (i < target)
	{
		pthread_mutex_destroy(&philo[i].meal_lock);
		i++;
	}
	free(philo);
}

void	clean_mutex_arr(pthread_mutex_t *target, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		pthread_mutex_destroy(&target[i]);
		i++;
	}
	if (target)
		free (target);
}

void	clean_data(t_data *data, bool mutex_init)
{
	if (mutex_init == true)
	{
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->status);
		if (data->forks)
			clean_mutex_arr(data->forks, data->input->nbr);
	}
	if (data->threads)
		free(data->threads);
	free(data->input);
	free(data);
}
