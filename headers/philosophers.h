/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:59 by owen          #+#    #+#                 */
/*   Updated: 2025/07/15 16:43:23 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define EXIT_GOOD		0
# define EXIT_BAD		1
# define GENERIC_ERR	"An error occured. Please try again"
# define MEM_ERR		"Malloc failure"
# define IN_COUNT_ERR	"Invalid input. Format is ./philosophers 1 2 3 4 (5)"
# define IN_CHAR_ERR	"Make sure the given value is a number"
# define IN_OVER_MAX	"Make sure the given value is a valid integer"
# define IN_UNDER_MIN	"Values must be larger than 0"
# define WARN_LIMIT		"One of the given values exceeds the recommended tests.\
 this can lead to performance issues and/or failure."
# define WARN_LIMIT_2	"One of the given values far exceeds the recommended\
 tests. this can lead to performance issues and/or failure."
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_input
{
	int				nbr;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meal_target;
}			t_input;


typedef struct s_data
{
	t_input			*input;
	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
	time_t			start;
	pthread_t		*threads;
	bool			debug;
	bool			infinite;
	bool			finish;
}			t_data;


typedef struct s_philo
{
	t_data			*data;
	int				id;
	int				times_eaten;
	time_t			last_meal;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
}			t_philo;

typedef enum e_print_type
{
	DEATH = 0,
	FINISH,
	EAT,
	SLEEP,
	THINK,
	FORK,
}			t_print_type;

/*cleanup*/
void	clean_mutex(pthread_mutex_t	*target);
/*eat_sleep_think*/
/*errors.c*/
int		error_msg(char *msg, int code);

/*main.c*/

/*parsing.c*/
int		parse_input(int argc, char **argv, t_data *data);

/*printing*/

/*setup_input*/
void	*init_input(void);

/*setup_philo*/
bool	fill_philosphers(t_data *data, t_philo *philo);
t_philo	*init_philos(t_data *data);

/*structs*/
void	*prepare_data(void);

/*threads*/
/*time*/
time_t	get_current_time(void);
time_t	get_start_time(t_data *data);


/*utils.c*/
int		ft_strlen(char *str);
int		convert_string(char *str, int *status);

#endif