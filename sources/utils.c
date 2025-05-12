/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:58:51 by owen          #+#    #+#                 */
/*   Updated: 2025/05/09 11:33:11 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
		return (idx);
	while (str[idx]);
		idx++;
	return (idx);
}

int	ft_atoi(const char *ptr)
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
	while (*ptr >= '0' && *ptr <= '9')
	{
		ret = ret * 10 + *ptr - '0';
		ptr++;
	}
	return (ret * negative);
}
