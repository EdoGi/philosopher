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

// TODO : PROTECT ALL MUTEXES LOCK and UNLOCK ! soudl return 0
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

// TODO : WHY get_time here is writer return ???
void	mtx_eating(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->ctxt->mtx_meal);
	if (i == 1)
		philo->last_eat = get_time();
	if (i == 2)
		philo->num_eat += 1;
	pthread_mutex_unlock(&philo->ctxt->mtx_meal);
}

int	eating(t_philo *philo)
{
	long int	start;

	start = philo->ctxt->start;
	if (philo->ctxt->itsok)
		return (1);
	lock_forks(philo);
	writer("\U0001F35D", "is eating", philo, philo->ctxt);
	mtx_eating(philo, 1);
	usleep(philo->ctxt->time_eat * 1000);
	unlock_forks(philo);
	mtx_eating(philo, 2);
	return (0);
}
