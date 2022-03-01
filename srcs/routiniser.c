/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routiniser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:31:17 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/01 21:54:28 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

// TODO : Create routine
int	routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		sleep(1);
	eat(philo);
	sleep(philo);
}

int	eat(t_philo *philo)
{
	long int	start;

	start = philo->ctxt->start;
	pthread_mutex_lock(&philo->right_fork);
	pthread_mutex_lock(&philo->left_fork);
	printf("%d : Philo %d is eating", get_time() - start, philo->id);
	usleep(philo->ctxt->time_eat * 1000);
	philo->num_eat += 1;
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	return (0);
}

int	sleep(t_philo *philo)
{
	long int	start;

	start = philo->ctxt->start;
	printf("%d : Philo %d is sleeping", get_time() - start, philo->id);
	usleep(philo->ctxt->time_eat * 1000);
	return (0);
}

int	thinking(t_philo *philo)
{
	long int	start;

	start = philo->ctxt->start;
	printf("%d : Philo %d is sleeping", get_time() - start, philo->id);
	usleep(philo->ctxt->time_eat * 1000);
	return (0);
}

int	check_death(t_philo *philo)
{
	long int	start;

	start = philo->ctxt->start;
	if (philo->starving >= philo->ctxt->time_eat)
	{
		printf("%d : Philo %d died", get_time() - start, philo->id);
		return (1);
	}
	return (0);
}
