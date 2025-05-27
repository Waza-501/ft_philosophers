/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 17:13:22 by owhearn       #+#    #+#                 */
/*   Updated: 2025/05/23 13:23:57 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	do_the_printing(char *str, t_philo *philo, bool debug)
{
	if (debug == false)
		printf("philospher %i is thinking....\n", philo->num);
}

void	*print_msg(t_data *data, t_philo *philo, bool debug)
{
	pthread_mutex_lock(data->print);
	do_the_printing("philospher %i is thinking....\n", philo, debug);
	pthread_mutex_unlock(data->print);
	return (NULL);
}
