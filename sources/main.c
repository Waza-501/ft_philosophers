/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:34 by owen          #+#    #+#                 */
/*   Updated: 2025/07/16 15:36:09 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	lone_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	print_msg(philo, FORK);
	/*sleep = time_to_die*/;
	print_msg(philo, DEATH);
	pthread_mutex_unlock(philo->fork1);
}

/*implement stagger, so have the odd philosophers think first*/
int	run_simulation(t_data *data)
{
	t_philo		*philo;
	int			i;

	i = 0;
	if (setup_data(data) == false)
		return (EXIT_BAD);
	philo = init_philos(data);
	while (i < data->input->nbr)
	{
		pthread_create(&data->threads[i], NULL, &philo_routine, \
(void *)&philo[i]);
		i++;
	}
	free(philo);
	return (EXIT_GOOD);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	data = prepare_data();
	if (!data)
		return (error_msg(MEM_ERR, 1));
	if (parse_input(argc, argv, data) != 0)
		return (EXIT_BAD);
	run_simulation(data);
	printf("exit time\n");
	clean_data(data);
	exit(0);
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