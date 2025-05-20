/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 17:13:22 by owhearn       #+#    #+#                 */
/*   Updated: 2025/05/20 17:15:31 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	do_the_printing(char *str, int num, bool debug)
{
	if (debug == false)
		printf("philospher %i is thinking....\n", num);
}

void	*print_msg(t_data *data, int num, bool debug)
{
	pthread_mutex_lock(data->print);
	do_the_printing("philospher %i is thinking....\n", num, debug);
	pthread_mutex_unlock(data->print);
	return (NULL);
}
