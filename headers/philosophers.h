/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:59 by owen          #+#    #+#                 */
/*   Updated: 2025/05/13 17:26:05 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define EXIT_GOOD		0
# define EXIT_BAD		1
# define GENERIC_ERR	"An error occured. Please try again"
# define IN_COUNT_ERR	"Invalid input. Format is ./philosophers 1 2 3 4 (5)"
# define IN_CHAR_ERR	"Make sure the given value is a number"
# define IN_OVER_MAX	"Make sure the given value is a valid integer"
# define IN_VALUE_ERR	"Make sure the given values are larger than 0"

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_data
{
	int		nbr;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		meal_target;
	bool	infinite;

}			t_data;


typedef struct s_philo
{
	t_data	data;
	int		num;
	int		last_dinner;
	int		times_eaten;
	bool	dead;
}			t_philo;


/*errors.c*/
int		error_msg(char *msg, int code);

/*main.c*/

/*parsing.c*/
int		parse_input(int argc, char **argv, t_data *data);

/*utils.c*/
int		ft_strlen(char *str);
int		convert_string(char *str, int *status);
void	*prepare_data(void);
#endif