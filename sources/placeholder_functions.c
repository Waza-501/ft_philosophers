/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   placeholder_functions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/04 12:07:03 by owen          #+#    #+#                 */
/*   Updated: 2025/06/04 12:55:20 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*set_mutex(pthread_mutex_t *src)
{
	int	ret;

	ret = 0;
	if (!pthread_mutex_init(src, NULL))
		return (1);
	return (0);
}
