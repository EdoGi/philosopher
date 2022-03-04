/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eater.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:05:06 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/04 23:39:05 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	mtx_num_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctxt->mtx_meal);
	philo->num_eat--;
	pthread_mutex_unlock(&philo->ctxt->mtx_meal);
}

int	meal_eating(t_philo *philo)
{
	if (philo->num_eat)
	{
		if (philo->id % 2 == 0)
			lock_forks_right_hand(philo);
		else
			lock_forks_left_hand(philo);
		writer("\U0001F35D", "is eating", philo, philo->ctxt);
		mtx_eat_timer(philo);
		usleep(philo->ctxt->time_eat * 1000);
		if (philo->id % 2 == 0)
			unlock_forks_right_hand(philo);
		else
			unlock_forks_left_hand(philo);
		mtx_num_eat(philo);
		return (0);
	}
	return (1);
}

int	infinite_eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
		lock_forks_right_hand(philo);
	else
		lock_forks_left_hand(philo);
	mtx_eat_timer(philo);
	writer("\U0001F35D", "is eating", philo, philo->ctxt);
	usleep(philo->ctxt->time_eat * 1000);
	if (philo->id % 2 == 0)
		unlock_forks_right_hand(philo);
	else
		unlock_forks_left_hand(philo);
	return (0);
}

int	eating(t_philo *philo)
{
	long int	start;

	start = philo->ctxt->start;
	if (check_ok(philo))
		return (1);
	pthread_mutex_lock(&philo->ctxt->mtx_meal);
	if (philo->ctxt->num_eat)
	{
		pthread_mutex_unlock(&philo->ctxt->mtx_meal);
		if (meal_eating(philo))
			return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->ctxt->mtx_meal);
		infinite_eating(philo);
	}
	return (0);
}
