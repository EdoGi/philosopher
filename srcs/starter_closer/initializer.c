/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:31:41 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/03 16:00:19 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_thread(t_data *context)
{
	int	i;

	i = 0;
	context->thrd = malloc(sizeof(pthread_t) * context->num_philo);
	if (context->thrd == NULL)
	{
		printf_error("thread malloc failed");
		return (1);
	}
	context->start = get_time();
	context->itsok = 0;
	while (i < context->num_philo)
	{
		if (pthread_create(&context->thrd[i], NULL, &routine, \
			&context->philo[i]) != 0)
		{
			printf_error("pthread create failed");
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_mutex(t_data *context)
{
	int	i;

	i = 0;
	context->forks = malloc(sizeof(pthread_mutex_t) * context->num_philo);
	if (context->forks == NULL)
	{
		printf_error("mutex malloc failed");
		return (1);
	}
	while (i < context->num_philo)
	{
		if (pthread_mutex_init(&context->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&context->mtx_write, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&context->mtx_meal, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&context->mtx_death, NULL) != 0)
		return (1);
	return (0);
}

int	init_philo(t_data *context)
{
	int		i;
	t_philo	*philo_set;

	context->philo = malloc(sizeof(t_philo) * context->num_philo);
	if (context->philo == NULL)
	{
		printf_error("philo malloc failed");
		return (1);
	}
	philo_set = context->philo;
	memset(philo_set, 0, sizeof(&philo_set));
	i = 0;
	while (i < context->num_philo)
	{
		philo_set[i].id = i + 1;
		philo_set[i].right_fork = context->forks[i];
		if (context->num_philo > 1)
			philo_set[i].left_fork = context->forks[(i + 1) \
				% context->num_philo];
		philo_set[i].ctxt = context;
		i++;
	}
	return (0);
}

int	init_context(int ac, char **av, t_data *context)
{
	memset(context, 0, sizeof(&context));
	if (parse_context(ac, av, context))
	{
		printf_error("Wrong Context !\n");
		usage();
		return (1);
	}
	if (init_mutex(context))
	{
		printf_error("init mutex failed\n");
		return (1);
	}
	if (init_philo(context))
	{
		printf_error("init philo failed\n");
		return (1);
	}
	if (init_thread(context))
	{
		printf_error("init thread failed\n");
		return (1);
	}
	return (0);
}
