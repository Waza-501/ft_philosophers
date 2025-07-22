/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:34 by owen          #+#    #+#                 */
/*   Updated: 2025/07/22 16:34:30 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	lone_philosopher(t_philo *philo)
{
	delay_start(philo->data);
	pthread_mutex_lock(philo->fork1);
	print_status(philo, FORK);
	ft_delay(philo->data, philo->data->input->time_die);
	print_status(philo, DEATH);
	pthread_mutex_unlock(philo->fork1);
}

bool	join_threads(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx <= data->input->nbr)
	{
		if (pthread_join(data->threads[idx], NULL) != 0)
			return (true);
		idx++;
	}
	return (false);
}

/*implement stagger, so have the odd philosophers think first*/
int	run_simulation(t_data *data)
{
	t_philo		*philo;
	int			i;
	int			idx = 0;

	i = 0;
	if (setup_data(data) == false)
		return (EXIT_BAD);
	philo = init_philos(data);
	if (data->input->nbr == 1)
		return (lone_philosopher(philo), EXIT_GOOD);
	while (i < data->input->nbr)
	{
		if (pthread_create(&data->threads[i], NULL, &philo_routine, \
(void *)&philo[i]) != 0)
			return (i);
		i++;
	}
	if (pthread_create(&data->threads[i], NULL, &monitor, (void *)philo) != 0)
		return (EXIT_BAD);
	if (join_threads(data) == true)
		return (printf("ahhhhhhhhhhhhhh\n"), EXIT_BAD);
	idx = 0;
	while (idx < philo->data->input->nbr)
	{
		printf("times philo %i has eaten: %i\n", philo[idx].id, philo[idx].times_eaten);
		idx++;
	}
	free(philo);
	return (EXIT_GOOD);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	data = prepare_data();
	if (!data)
		return (print_msg_fd(MEM_ERR, 1));
	if (parse_input(argc, argv, data) != 0)
		return (EXIT_BAD);
	run_simulation(data);
	clean_data(data);
	return (0);
}
