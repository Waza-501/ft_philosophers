/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:59 by owen          #+#    #+#                 */
/*   Updated: 2025/04/21 11:03:30 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHISOPHERS_H
# define PHILOSOPHERS_H

# define EXIT_GOOD		0
# define EXIT_BAD		1
# define GENERIC_ERR	"An error occured. Please try again"

# include <stdbool.h>

typedef struct s_data
{
	int		nbr;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		times_eaten;
	bool	infinite;

}			t_data;


typedef struct	s_philo
{
	t_data	data;
	int		num;
	int		last_dinner;
	int		times_eaten;
}			t_philo;


/*errors.c*/
int		error_msg(char *msg, int code);

/*utils.c*/
int		ft_strlen(char *str);
#endif