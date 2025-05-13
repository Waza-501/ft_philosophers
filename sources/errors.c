/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:57:37 by owen          #+#    #+#                 */
/*   Updated: 2025/05/12 15:51:07 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_msg(char *msg, int code)
{
	write (stderr, "Error: ", 7);
	if (msg)
		write(2, msg, ft_strlen(msg));
	else
		write(2, GENERIC_ERR, ft_strlen(GENERIC_ERR));
	return (code);
}
