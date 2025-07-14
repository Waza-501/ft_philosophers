/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 13:47:34 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/14 13:49:20 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*init_input(void)
{
	t_input	*new;

	new = (t_input *)malloc(sizeof(t_input));
	if (!new)
		return (NULL);
	new->philonbr = 0;
	new->time_die = 0;
	new->time_eat = 0;
	new->time_sleep = 0;
	new->meal_target = 0;
	return (new);
}
