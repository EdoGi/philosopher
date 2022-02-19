/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:27:49 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/19 20:03:45 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

// TODO : Complete context structure
typedef struct s_data
{
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_eat;
}	t_data;

// TODO : Create philo structure

#endif