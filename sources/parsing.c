/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 14:20:48 by owhearn       #+#    #+#                 */
/*   Updated: 2025/07/14 14:03:13 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	verify_input(int argc, t_input *input)
{
	int	ret_status;

	ret_status = 0;
	if (input->philonbr == 0 || input->time_die == 0 || input->time_eat == 0
		|| input->time_sleep == 0)
		ret_status = error_msg(IN_UNDER_MIN, 1);
	if (argc == 6 && ret_status == 0)
	{
		if (input->meal_target < 1)
			ret_status = error_msg(IN_UNDER_MIN, 1);
	}
	if (input->philonbr > 250 || input->time_die > 250 || input->time_eat > 250
		|| input->time_sleep > 250)
		ret_status = error_msg(WARN_LIMIT, 0);
	/*if (ret_status == 0)
	{
		printf("ret status is %i\n", ret_status);
		input->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t *)
				* (input->philonbr));
		if (!input->forks)
			ret_status = error_msg(MEM_ERR, 1);
	}*/
	return (ret_status);
}

int	convert_args(int argc, char **argv, t_input	*input)
{
	int	ret_status;

	ret_status = 0;
	input->philonbr = convert_string(argv[1], &ret_status);
	if (ret_status == 0)
		input->time_die = convert_string(argv[2], &ret_status);
	if (ret_status == 0)
		input->time_eat = convert_string(argv[3], &ret_status);
	if (ret_status == 0)
		input->time_sleep = convert_string(argv[4], &ret_status);
	if (argc == 6 && ret_status == 0)
	{
		input->meal_target = convert_string(argv[5], &ret_status);
		//input->infinite = false;
	}
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
			data->infinite = true;
	}
	else
		error_msg(IN_COUNT_ERR, 1);
	return (status);
}
