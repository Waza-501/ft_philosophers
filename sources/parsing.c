/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 14:20:48 by owhearn       #+#    #+#                 */
/*   Updated: 2025/09/10 13:38:38 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	input_over_limit(t_input *input)
{
	if (input->nbr > 400)
		return (true);
	return (false);
}

bool	warn_input(t_input *input)
{
	bool	warn;

	warn = false;
	if (input->nbr > 200)
		warn = true;
	else if (input->time_die < input->time_eat || input->time_die
		< input->time_sleep || input->time_die
		< (input->time_eat + input->time_sleep + 5))
		warn = true;
	return (warn);
}

int	verify_input(int argc, t_input *input)
{
	int	ret_status;

	ret_status = 0;
	if (input->nbr == 0 || input->time_die == 0 || input->time_eat == 0
		|| input->time_sleep == 0)
		ret_status = print_msg_fd(IN_UNDER_MIN, 1);
	if (argc == 6 && ret_status == 0)
	{
		if (input->meal_target < 1)
			ret_status = print_msg_fd(IN_UNDER_MIN, 1);
	}
	if (warn_input(input) == true)
		if (input_over_limit(input) == true)
			ret_status = print_msg_fd(OVER_LIMIT, 1);
	return (ret_status);
}

int	convert_args(int argc, char **argv, t_input	*input)
{
	int	ret_status;

	ret_status = 0;
	input->nbr = convert_string(argv[1], &ret_status);
	if (ret_status == 0)
		input->time_die = convert_string(argv[2], &ret_status);
	if (ret_status == 0)
		input->time_eat = convert_string(argv[3], &ret_status);
	if (ret_status == 0)
		input->time_sleep = convert_string(argv[4], &ret_status);
	if (argc == 6 && ret_status == 0)
		input->meal_target = convert_string(argv[5], &ret_status);
	if (ret_status == 0)
		ret_status = verify_input(argc, input);
	return (ret_status);
}

int	parse_input(int argc, char **argv, t_data *data)
{
	int	status;

	status = 1;
	if (argc == 5 || argc == 6)
	{
		status = convert_args(argc, argv, data->input);
		if (argc == 6)
			data->infinite = false;
	}
	else
		print_msg_fd(IN_COUNT_ERR, 1);
	return (status);
}
