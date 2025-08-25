/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 11:29:47 by owhearn       #+#    #+#                 */
/*   Updated: 2025/08/16 01:57:47 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	join_threads(t_data *data, int target, bool error)
{
	int	idx;

	idx = 0;
	if (error == true)
		set_finish(data);
	while (idx <= target)
	{
		if (pthread_join(data->threads[idx], NULL) != 0)
			return (true);
		idx++;
	}
	return (false);
}

int	create_philo_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input->nbr)
	{
		if (pthread_create(&data->threads[i], NULL, &philo_routine,
				(void *)&philo[i]) != 0)
			return (i);
		i++;
	}
	return (i);
}

