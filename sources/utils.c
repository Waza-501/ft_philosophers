/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:58:51 by owen          #+#    #+#                 */
/*   Updated: 2025/05/13 17:27:03 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
		return (idx);
	while (str[idx])
		idx++;
	return (idx);
}

int	ft_atoi(const char *ptr, int *status)
{
	long	ret;
	int		negative;

	ret = 0;
	negative = 1;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			negative *= -1;
		ptr++;
	}
	while (*ptr)
	{
		if (*ptr >= '0' && *ptr <= '9')
			ret = ret * 10 + *ptr - '0';
		else
		{
			status = error_msg(IN_CHAR_ERR, 1);
			return (0);
		}
		ptr++;
	}
	return (ret * negative);
}

int	convert_string(char *str, int *status)
{
	long	value;

	value = 0;
	value = ft_atoi(str, status);
	if ((value < INT_MIN || value > INT_MAX) && status == 0)
	{
		error_msg(IN_OVER_MAX, 1);
		status = 1;
	}
	return (value);
}

void	*prepare_data(void)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->nbr = 0;
	new->time_die = 0;
	new->time_eat = 0;
	new->time_sleep = 0;
	new->meal_target = 0;
	new->infinite = true;
	return (new);
}
