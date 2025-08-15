/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:34 by owen          #+#    #+#                 */
/*   Updated: 2025/08/15 17:40:28 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

/*temporary testing function*/
void	print_times_eaten(t_philo *philo, int target)
{
	int	idx;

	idx = 0;
	while (idx < target)
	{
		printf("times philo %i has eaten: %i\n", philo[idx].id,
			philo[idx].times_eaten);
		idx++;
	}
}

void	lone_philosopher(t_philo *philo)
{
	delay_start(philo->data);
	pthread_mutex_lock(philo->fork1);
	print_status(philo, FORK);
	ft_delay(philo->data, philo->data->input->time_die);
	print_status(philo, DEATH);
	pthread_mutex_unlock(philo->fork1);
}

int	run_simulation(t_data *data)
{
	t_philo		*philo;
	int			i;

	i = 0;
	if (setup_data(data) == false)
		return (EXIT_BAD);
	philo = init_philos(data);
	if (!philo)
		return (EXIT_BAD);
	if (data->input->nbr == 1)
		return (lone_philosopher(philo), EXIT_GOOD);
	i = create_philo_threads(philo, data);
	if (i != (data->input->nbr - 1))
		return (join_threads(data, (i - 1)), free(philo), EXIT_BAD);
	else if (pthread_create(&data->threads[i], NULL, &monitor, (void *)philo) != 0)
		return (join_threads(data, data->input->nbr - 1), free(philo), EXIT_BAD);
	if (join_threads(data, data->input->nbr) == true)
		return (printf("ahhhhhhhhhhhhhh\n"), free(philo), EXIT_BAD);
	print_times_eaten(philo, philo->data->input->nbr);
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
		return (clean_data(data, false), EXIT_BAD);
	run_simulation(data);
	clean_data(data, true);
	return (0);
}
