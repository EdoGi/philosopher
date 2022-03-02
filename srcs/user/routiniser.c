/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routiniser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:31:17 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/02 00:49:50 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

// TODO : Create routine
int	routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(100 * philo->ctxt->num_philo);
	while (philo->ctxt->itsok == 0)
	{
		if (think(philo))
			return (0);
		if (eat(philo))
			return (0);
		if (sleep(philo))
			return (0);
	}
	return (0);
}

int	think(t_philo *philo)
{
	if (philo->ctxt->itsok)
		return (1);
	writer("\U0001F914", "is thinking", philo, philo->ctxt);
	return (0);
}

int	eat(t_philo *philo)
{
	long int	start;

	start = philo->ctxt->start;
	if (philo->ctxt->itsok)
		return (1);
	pthread_mutex_lock(&philo->right_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	pthread_mutex_lock(&philo->left_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	writer("\U0001F35D", "is eating", philo, philo->ctxt);
	usleep(philo->ctxt->time_eat * 1000);
	philo->num_eat += 1;
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	return (0);
}

int	sleep(t_philo *philo)
{
	if (philo->ctxt->itsok)
		return (1);
	writer("\U0001F634", "is sleeping", philo, philo->ctxt);
	usleep(philo->ctxt->time_eat * 1000);
	return (0);
}
