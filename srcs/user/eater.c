/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eater.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:05:06 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/03 15:03:04 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	pthread_mutex_lock(&philo->left_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

int	eating(t_philo *philo)
{
	long int	start;

	start = philo->ctxt->start;
	if (philo->ctxt->itsok)
		return (1);
	lock_forks(philo);
	writer("\U0001F35D", "is eating", philo, philo->ctxt);
	usleep(philo->ctxt->time_eat * 1000);
	philo->num_eat += 1;
	philo->last_eat = get_time();
	unlock_forks(philo);
	return (0);
}
