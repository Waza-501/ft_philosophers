/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:34 by owen          #+#    #+#                 */
/*   Updated: 2025/07/14 13:57:43 by owhearn       ########   odam.nl         */
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

int	run_simulation(t_data *data)
{
	t_philo		*philo_arr;

	philo_arr = configure_philos(data);
	/*implement stagger, so have the odd philosophers think first*/
	return (EXIT_GOOD);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	data = prepare_data();
	if (!data)
		return (error_msg(MEM_ERR, 1));
	if (parse_input(argc, argv, data->input))
		return (1);
	run_simulation(data);
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