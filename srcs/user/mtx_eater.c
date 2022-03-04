/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_eater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:32:29 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/04 23:37:43 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	lock_forks_right_hand(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	pthread_mutex_lock(philo->left_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
}

void	lock_forks_left_hand(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	pthread_mutex_lock(philo->right_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
}

void	unlock_forks_right_hand(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	unlock_forks_left_hand(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	mtx_eat_timer(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctxt->mtx_meal);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->ctxt->mtx_meal);
}
