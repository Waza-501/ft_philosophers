/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 11:29:47 by owhearn       #+#    #+#                 */
/*   Updated: 2025/08/13 11:30:24 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	join_threads(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx <= data->input->nbr)
	{
		if (pthread_join(data->threads[idx], NULL) != 0)
			return (true);
		idx++;
	}
	return (false);
}
