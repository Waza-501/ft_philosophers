/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wip_todo_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/04 12:07:03 by owen          #+#    #+#                 */
/*   Updated: 2025/08/15 12:36:49 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	init_mutex(pthread_mutex_t	*mutex)
{
	if (pthread_mutex_init(mutex, NULL))
		return (false);
	return (true);
}

void	set_finish(t_data *data)
{
	pthread_mutex_lock(&data->status);
	data->finish = true;
	pthread_mutex_unlock(&data->status);
}

bool	check_status(t_data *data)
{
	bool	status;

	pthread_mutex_lock(&data->status);
	status = data->finish;
	pthread_mutex_unlock(&data->status);
	return (status);
}
