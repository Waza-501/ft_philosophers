/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:34 by owen          #+#    #+#                 */
/*   Updated: 2025/05/27 17:19:24 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

bool	init_mutex(t_data *data)
{
	if (pthread_mutex_init(data->print, NULL))
		return (false);
	return (true);
}

int	run_simulation(t_data *data, t_philo *p_data)
{
	if (init_mutex(data) == false)
		return (EXIT_BAD);
		
	return (EXIT_GOOD);
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
	philo_arr = create_philosophers(data);
	if (!philo_arr)
		return (error_msg("oopsie", 1));
	if (fill_philosphers(data, philo_arr) == false)
		return (error_msg("oopsie \n", 1));
	run_simulation(data, philo_arr);
	//run_test_threads(philo_arr, data);
	free(philo_arr);
	pthread_mutex_destroy(data->print);
	free(data);
	return (0);
}


/*void	*test_case(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		print_msg(philo->data, philo->num);
		philo->times_eaten++;
		sleep(0.1 + (rand() % 10 + 1));
	}
	return (NULL);
}

void	run_test_threads(t_philo *philo, t_data *data)
{
	int			i;

	i = 0;
	while (i < data->philonbr)
	{
		pthread_create(&philo[i].thread, NULL, test_case, &philo[i]);
		i++;
	}
	sleep(20);
	i = 0;
	while (i < data->philonbr)
	{
		pthread_cancel(philo[i].thread);
		i++;
	}
	printf("test done\n");
	i = 0;
	while (i < data->philonbr)
	{
		printf("times philo %i vibed: %i\n", philo[i].num, philo[i].times_eaten);
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	exit (0);
}*/