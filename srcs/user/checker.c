/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:01:23 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/04 19:08:45 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_ok(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctxt->mtx_death);
	if (philo->ctxt->end == 1)
	{
		pthread_mutex_unlock(&philo->ctxt->mtx_death);
		return (1);
	}
	pthread_mutex_unlock(&philo->ctxt->mtx_death);
	return (0);
}

int	is_dead(t_philo *philo)
{
	int			i;
	long int	die_time;

	i = 0;
	pthread_mutex_lock(&philo->ctxt->mtx_death);
	philo->ctxt->end = 1;
	die_time = get_time() - philo->ctxt->start;
	pthread_mutex_unlock(&philo->ctxt->mtx_death);
	// pthread_mutex_lock(&philo->ctxt->mtx_write);
	printf("\U0001F480 %ld ms : Philo %d died\n", die_time, philo->id);
	// pthread_mutex_unlock(&philo->ctxt->mtx_write);
	return (0);
}

int	check_death(t_data *context)
{
	long int	start;
	long int	starving;
	int			i;

	start = context->start;
	i = 0;
	while (i < context->num_philo)
	{
		pthread_mutex_lock(&context->mtx_meal);
		starving = get_time() - context->philo[i].last_eat;
		pthread_mutex_unlock(&context->mtx_meal);
		if (starving >= context->time_die)
		{
			is_dead(&context->philo[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_eat(t_data *context)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < context->num_philo)
	{
		if (context->philo[i].num_eat == 0)
			count++;
		i++;
	}
	if (count < context->num_philo)
		return (0);
	else
		return (1);
}

int	check_end(t_data *context)
{
	int	i;

	i = 0;
	while (i < context->num_philo)
	{
		if (context->num_eat)
		{
			if (check_eat(context))
			{
				printf("Everybody Miamiamed !\n");
				return (1);
			}
		}
		if (check_death(context))
			return (1);
		i++;
	}
	return (0);
}
