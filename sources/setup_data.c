/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 16:06:21 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/15 16:21:53 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*prepare_data(void)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->input = init_input();
	if (!new->input)
		return (free(new), NULL);
	new->print = 0;
	new->infinite = true;
	new->finish = false;
	return (new);
}
