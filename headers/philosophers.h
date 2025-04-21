/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:27:59 by owen          #+#    #+#                 */
/*   Updated: 2025/04/21 10:42:40 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHISOPHERS_H
# define PHILOSOPHERS_H

# define EXIT_GOOD	0
# define EXIT_BAD	1

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
	int		num;
}			t_philo;


#endif