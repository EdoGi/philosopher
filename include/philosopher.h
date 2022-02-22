/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:27:49 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/22 17:07:56 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// FIXME : Complete context structure
typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	pthread_mutex_t	forks;
	struct s_philo	*philo;
}	t_data;

// FIXME : Complete philo structure
typedef struct s_philo
{
	int				id;
	int				num_eat;
	int				starving;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*ctxt;
}	t_philo;

#endif