/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 14:20:48 by owhearn       #+#    #+#                 */
/*   Updated: 2025/05/13 17:06:00 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	verify_input(t_data *data)
{
	int	ret_status;

	ret_status = 0;
	if (data->time_die < 1 || data->time_eat < 1 || data->time_sleep < 1)
		ret_status = error_msg(IN_VALUE_ERR, 1);
	if (data->infinite == false && ret_status == 0)
	{
		if (data->meal_target < 1)
			ret_status = error_msg(IN_VALUE_ERR, 1);
	}
	return (ret_status);
}

int	convert_args(int argc, char **argv, t_data *data)
{
	int	ret_status;

	ret_status = 0;
	data->time_die = convert_string(argv[1], &ret_status);
	if (ret_status == 0)
		data->time_eat = convert_string(argv[2], &ret_status);
	if (ret_status == 0)
		data->time_sleep = convert_string(argv[3], &ret_status);
	if (argc == 6 && ret_status == 0)
	{
		data->meal_target = convert_string(argv[4], &ret_status);
		data->infinite == false;
	}
	if (ret_status == 0)
		ret_status = verify_input(data);
	return (ret_status);
}

int	parse_input(int argc, char **argv, t_data *data)
{
	int	status;

	status = 1;
	if (argc == 5 || argc == 6)
		status = convert_args(argc, argv, data);
	else
		error_msg(IN_COUNT_ERR, 1);
	return (status);
}
