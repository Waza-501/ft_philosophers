/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:34 by owen          #+#    #+#                 */
/*   Updated: 2025/05/19 13:52:35 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

t_philo	*create_philosophers(t_data *data)
{
	t_philo	*new_arr;

	new_arr = (t_philo *)malloc(sizeof(t_philo) * (data->philonbr + 1));
	if (!new_arr)
		return (NULL);
	return (new_arr);
}

void	*test_case(void *arg)
{
	printf("haha whoopsie says philosopher\n");
	printf("Won't happen again!\n");
	while (1)
	{
		printf("philospher is thinking....\n");
		sleep(1);
	}
	return NULL;
}

/*int	run_simulation(t_data *data, t_philo *p_data)
{
	
	return (EXIT_GOOD);
}*/

void	run_test_threads(t_data *data)
{
	pthread_t	test_1;

	pthread_create(&test_1, NULL, test_case, NULL);
	sleep(10);
	pthread_cancel(test_1);
	pthread_join(test_1, NULL);
	printf("test done\n");
	exit (0);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo_arr;

	data = prepare_data();
	if (!data)
		return (error_msg(MEM_ERR, 1));
	if (parse_input(argc, argv, data))
		return (1);
	printf("stored values are %i philosophers, %i time to die, %i time to eat, %i time to sleep\n", data->philonbr, data->time_die, data->time_eat,data->time_sleep);
	philo_arr = create_philosophers(data);
	if (!philo_arr)
		return (error_msg("oopsie", 1));
	//run_simulation(data, philo_arr);
	free(philo_arr);
	run_test_threads(data);
	free(data);
	return (0);
}
