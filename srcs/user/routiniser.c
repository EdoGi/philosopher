/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routiniser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:31:17 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/03 15:02:15 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// TODO : Create routine
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = philo->ctxt->start;
	if (philo->id % 2 == 0)
		usleep(100 * philo->ctxt->num_philo);
	while (philo->ctxt->itsok == 0)
	{
		if (thinking(philo))
			return (0);
		if (eating(philo))
			return (0);
		if (sleeping(philo))
			return (0);
	}
	return (0);
}

int	thinking(t_philo *philo)
{
	if (philo->ctxt->itsok)
		return (1);
	writer("\U0001F914", "is thinking", philo, philo->ctxt);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (philo->ctxt->itsok)
		return (1);
	writer("\U0001F634", "is sleeping", philo, philo->ctxt);
	usleep(philo->ctxt->time_eat * 1000);
	return (0);
}
