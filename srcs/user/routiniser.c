/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routiniser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:31:17 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/04 20:42:51 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	sad_and_alone(t_philo *philo)
{
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	usleep(philo->ctxt->time_die * 1000);
}

int	thinking(t_philo *philo)
{
	int	t_eat;
	int	t_die;
	int	t_sleep;

	t_eat = philo->ctxt->time_eat;
	t_die = philo->ctxt->time_die;
	t_sleep = philo->ctxt->time_sleep;
	if (check_ok(philo))
		return (1);
	usleep(1000);
	// usleep((t_die - t_eat - t_sleep) / 2 * 1000);
	writer("\U0001F4AD", "is thinking", philo, philo->ctxt);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (check_ok(philo))
		return (1);
	writer("\U0001F4A4", "is sleeping", philo, philo->ctxt);
	usleep(philo->ctxt->time_sleep * 1000);
	return (0);
}

// FIXME : FIX routine
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->ctxt->num_philo == 1)
	{
		sad_and_alone(philo);
		return (0);
	}
	while (check_ok(philo) == 0)
	{
		if (thinking(philo))
			return (0);
		// printf("after thinking time philo %d is %ld\n", philo->id, get_time());
		if (eating(philo))
			return (0);
		if (sleeping(philo))
			return (0);
	}
	return (0);
}
