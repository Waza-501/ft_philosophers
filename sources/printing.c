/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 17:13:22 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/15 15:43:04 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	do_the_printing(char *str, t_philo *philo)
{
	if (philo->data->debug == false)
		printf("%ld philospher %i %s\n", get_current_time(), philo->id, str);
}

void	*print_msg(t_philo *philo, t_print_type type)
{
	pthread_mutex_lock(philo->data->print);
	if (type == DEATH)
		do_the_printing("has died", philo);
	else if (type == FINISH)
		do_the_printing("ending simulation.", philo);
	else if (type == EAT)
		do_the_printing("is eating", philo);
	else if (type == SLEEP)
		do_the_printing("is sleeping", philo);
	else if (type == THINK)
		do_the_printing("is thinking", philo);
	else if (type == FORK)
		do_the_printing("has taken a fork", philo);
	pthread_mutex_unlock(philo->data->print);
	return (NULL);
}
