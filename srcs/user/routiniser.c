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

void	sad_and_alone(t_philo *philo)
{
	writer("\U0001F374", "has taken a fork", philo, philo->ctxt);
	usleep(philo->ctxt->time_die * 1000);
	writer("\U0001F480", "died", philo, philo->ctxt);
}

// FIXME : FIX routine
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = philo->ctxt->start;
	if (philo->ctxt->num_philo == 1)
	{
		sad_and_alone(philo);
		return (0);
	}
	if (philo->id % 2 == 0)
		usleep(100 * philo->ctxt->num_philo);
	while (philo->ctxt->itsok == 0)
	{
		if (thinking(philo))
			return (0);
		if (philo->ctxt->num_eat)
		{
			if (philo->num_eat < philo->ctxt->num_eat)
			{
				if (eating(philo))
					return (0);
			}
			else
				return (0);
		}
		else
		{
			if (eating(philo))
				return (0);			
		}
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
	usleep(philo->ctxt->time_sleep * 1000);
	return (0);
}
