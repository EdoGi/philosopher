/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:27:49 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/23 13:22:50 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define RED "\033[1;31m"
# define RED_BLINK "\033[1;5;31m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;36m"
# define GREEN "\033[0;32m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

// FIXME : Complete context structure
typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	pthread_t		*thrd;
	pthread_mutex_t	*forks;
	struct s_philo	*philo;
	int				actime;
}	t_data;

// FIXME : Complete philo structure
typedef struct s_philo
{
	int				id;
	int				num_eat;
	int				starving;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	t_data			*ctxt;
}	t_philo;

#endif