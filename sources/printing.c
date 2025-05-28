/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 17:13:22 by owhearn       #+#    #+#                 */
/*   Updated: 2025/05/27 14:36:34 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	do_the_printing(char *str, t_philo *philo, bool debug)
{
	if (debug == false)
		printf("philospher %i %s\n", philo->num, str);
}

void	*print_msg(t_philo *philo, t_print_type type, bool debug)
{
	pthread_mutex_lock(philo->data->print);
	if (type == DEATH)
		do_the_printing("has died", philo, debug);
	else if (type == FINISH)
		do_the_printing("ending simulation.", philo, debug);
	else if (type == EAT)
		do_the_printing("is eating", philo, debug);
	else if (type == SLEEP)
		do_the_printing("is sleeping", philo, debug);
	else if (type == THINK)
		do_the_printing("is thinking", philo, debug);
	else if (type == FORK)
		do_the_printing("has taken a fork", philo, debug);
	pthread_mutex_unlock(philo->data->print);
	return (NULL);
}
