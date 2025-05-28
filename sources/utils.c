/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:58:51 by owen          #+#    #+#                 */
/*   Updated: 2025/05/27 16:06:30 by owhearn       ########   odam.nl         */
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

int	str_isdigit(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx])
	{
		if ((str[idx] < '0' || str[idx] > '9'))
			return (1);
		idx++;
	}
	return (0);
}

long	ft_atoi(const char *ptr, int *status)
{
	long long	ret;
	int			negative;

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

int	convert_string(char *str, int *status)
{
	long	value;

	value = 0;
	if (str_isdigit(str))
		*status = error_msg(IN_CHAR_ERR, 1);
	value = ft_atoi(str, status);
	if (value < 0 && *status == 0)
		*status = error_msg(IN_UNDER_MIN, 1);
	if (value > INT_MAX && *status == 0)
		*status = error_msg(IN_OVER_MAX, 1);
	return (value);
}
