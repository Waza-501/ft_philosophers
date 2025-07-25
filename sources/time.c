/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 14:47:20 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/18 12:27:54 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*Returns the time since the Epoch in ms*/
time_t	get_current_time(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

time_t	get_start_time(t_data *data)
{
	return (get_current_time() + (10 * data->input->nbr));
}

void	delay_start(t_data *data)
{
	while (check_status(data) == false && get_current_time() < data->start)
		continue ;
}
