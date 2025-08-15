/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 14:47:20 by owhearn       #+#    #+#                 */
/*   Updated: 2025/08/13 11:31:21 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_delay(t_data *data, size_t delay)
{
	time_t	target;

	target = get_current_time() + delay;
	while (get_current_time() < target)
	{
		if (check_status(data) == true)
			break ;
		usleep(500);
	}
}

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
