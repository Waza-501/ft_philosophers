/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wip_todo_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/04 12:07:03 by owen          #+#    #+#                 */
/*   Updated: 2025/07/24 14:05:53 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	set_mutex(pthread_mutex_t *src)
{
	if (!pthread_mutex_init(src, NULL))
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
