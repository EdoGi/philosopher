/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_eater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:32:29 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/04 20:19:36 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// TODO : PROTECT ALL MUTEXES LOCK and UNLOCK ! sould return 0
void	lock_forks_right_hand(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	// printf("right fork taken : %p\n", &philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	// printf("left fork taken : %p\n", &philo->left_fork);
}

void	lock_forks_left_hand(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	// printf("left fork taken : %p\n", &philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	// printf("right fork taken : %p\n", &philo->right_fork);
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
	// printf("\tlast eat is %ld\n", philo->last_eat);
	philo->last_eat = get_time();
	// printf("\tlast eat is %ld\n", philo->last_eat);
	pthread_mutex_unlock(&philo->ctxt->mtx_meal);
}

/* 
void	mtx_num_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctxt->mtx_meal);
	philo->num_eat--;
	pthread_mutex_unlock(&philo->ctxt->mtx_meal);
}
*/