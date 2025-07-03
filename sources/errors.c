/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:57:37 by owen          #+#    #+#                 */
/*   Updated: 2025/06/10 12:13:31 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_msg(char *msg, int code)
{
	write (2, "Error: ", 7);
	if (msg)
		write(2, msg, ft_strlen(msg));
	else
		write(2, GENERIC_ERR, ft_strlen(GENERIC_ERR));
	write(2, "\n", 1);
	return (code);
}

int	error_cleanup(t_data *data)
{
	
}

int	error_fcleanup(t_philo *philo)
{

}
