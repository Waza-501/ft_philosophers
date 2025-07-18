/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:59 by owen          #+#    #+#                 */
/*   Updated: 2025/07/17 16:10:29 by owen          ########   odam.nl         */
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
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	status;
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
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
}			t_philo;

typedef enum e_clear_type
{
	ALL = 0,
	NONE,
	THREADS,
	FORKS,
}			t_clear_type;
/*sleep = time_to_die*/;
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
void			clean_philos(t_philo *philo, int target);
void			clean_multimutex(pthread_mutex_t *target, int nbr);
void			clean_data(t_data *data);
void			clean_mutex(pthread_mutex_t	*target);

/*errors.c*/
int				error_msg(char *msg, int code);

/*forks.c*/
pthread_mutex_t	*create_forks(int nbr);

/*main.c*/

/*parsing.c*/
int				parse_input(int argc, char **argv, t_data *data);

/*printing*/
void			*print_msg(t_philo *philo, t_print_type type);

/*routine.c*/

void			ft_sleep(t_data *data, size_t delay);
void			*philo_routine(void *input);

/*setup_data*/
bool			setup_data(t_data *data);
void			*prepare_data(void);

/*setup_input*/
void			*init_input(void);

/*setup_philo*/
bool			fill_philosphers(t_data *data, t_philo *philo);
t_philo			*init_philos(t_data *data);

/*structs*/
void			*prepare_data(void);

/*threads*/
/*time*/
time_t			get_current_time(void);
time_t			get_start_time(t_data *data);
void			delay_start(t_data *data);

/*utils.c*/
int				ft_strlen(char *str);
int				convert_string(char *str, int *status);
bool			init_mutex(pthread_mutex_t	*mutex);

/*wip_todo_functions.c*/
pthread_mutex_t	*set_mutex(pthread_mutex_t *src);
void			set_finish(t_data *data);
bool			check_status(t_data *data);

#endif