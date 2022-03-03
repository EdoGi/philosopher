/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:01:23 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/03 15:14:00 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_death(t_philo *philo)
{
	long int	start;
	long int	starving;

	start = philo->ctxt->start;
	pthread_mutex_lock(&philo->ctxt->mtx_meal);
	starving = get_time() - philo->last_eat;
	pthread_mutex_unlock(&philo->ctxt->mtx_meal);
	if (starving >= philo->ctxt->time_die)
	{
		writer("\U0001F480", "died", philo, philo->ctxt);
		return (1);
	}
	return (0);
}

int	check_eat(t_philo *philo)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < philo->ctxt->num_philo)
	{
		pthread_mutex_lock(&philo->ctxt->mtx_meal);
		if (philo[i].num_eat >= philo->ctxt->num_eat)
			count++;
		pthread_mutex_unlock(&philo->ctxt->mtx_meal);
		i++;
	}
	if (count < philo->ctxt->num_philo)
		return (0);
	else
		return (1);
}

int	is_it_ok(t_data *context)
{
	int	i;

	i = 0;
	while (i < context->num_philo)
	{
		if (check_death(&context->philo[i]))
			return (1);
		i++;
	}
	i = 0;
	if (check_eat(context->philo))
	{
		printf("Everybody Miamiamed !\n");
		return (1);
	}
	return (0);
}
