/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 17:13:22 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/22 16:55:30 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_msg_fd(char *msg, int code)
{
	if (code == 1)
	{
		write (2, "Error: ", 7);
		if (msg)
			write(2, msg, ft_strlen(msg));
		else
			write(2, GENERIC_ERR, ft_strlen(GENERIC_ERR));
	}
	else
		write (1, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (code);
}

void	do_the_printing(char *str, t_philo *philo)
{
	if (philo->data->debug == false)
		printf("%ld philosopher %i %s\n", get_current_time() - philo->data->start\
, philo->id, str);
}

void	*print_status(t_philo *philo, t_print_type type)
{
	pthread_mutex_lock(&philo->data->print);
	if (check_status(philo->data) == true)
		return (pthread_mutex_unlock(&philo->data->print), NULL);
	if (type == DEATH)
		do_the_printing("has died", philo);
	else if (type == FINISH)
		printf("End condition reached. Ending simulation.\n");
	else if (type == EAT)
		do_the_printing("is eating", philo);
	else if (type == SLEEP)
		do_the_printing("is sleeping", philo);
	else if (type == THINK)
		do_the_printing("is thinking", philo);
	else if (type == FORK)
		do_the_printing("has taken a fork", philo);
	pthread_mutex_unlock(&philo->data->print);
	return (NULL);
}
