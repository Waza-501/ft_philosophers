/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wip_todo_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/04 12:07:03 by owen          #+#    #+#                 */
/*   Updated: 2025/07/17 13:29:29 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

pthread_mutex_t	*set_mutex(pthread_mutex_t *src)
{
	int	ret;

	ret = 0;
	if (!pthread_mutex_init(src, NULL))
		return (1);
	return (0);
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
