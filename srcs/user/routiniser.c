/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routiniser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:31:17 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/02 02:03:03 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

// TODO : Create routine
int	routine(t_philo *philo)
{
	philo->last_eat = philo->ctxt->start;
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
