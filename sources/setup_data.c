/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 16:06:21 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/19 18:27:10 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	setup_data(t_data *data)
{
	if (init_mutex(&data->print) == false)
		return (false);
	if (init_mutex(&data->status) == false)
		return (false);
	data->forks = create_forks(data->input->nbr);
	if (!data->forks)
		return (false);
	data->start = get_start_time(data);
	data->threads = (pthread_t *)malloc(sizeof(pthread_t) * (data->input->nbr + 1));
	if (!data->threads)
		return (clean_multimutex(data->forks, data->input->nbr), false);
	return (true);
}

void	*prepare_data(void)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->input = init_input();
	if (!new->input)
		return (free(new), NULL);
	new->forks = NULL;
	new->start = 0;
	new->threads = NULL;
	new->debug = false;
	new->infinite = true;
	new->finish = false;
	return (new);
}
