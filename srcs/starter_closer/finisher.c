/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finisher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:15:36 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/04 21:57:58 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// FIXME : Complete this function with all usages ;
void	usage(void)
{
	printf("USAGE :\nLaunch : ./Philo <number_of_philosophers> <time_to_die>");
	printf(" <time_to_eat> <time_to_sleep>");
	printf(" <Optional:number_of_times_each_philosopher_must_eat>\n\n");
}

int	the_end(t_data *context)
{
	if (context)
	{
		memset(context, 0, sizeof(&context));
		context = NULL;
	}
	exit (0);
	return (0);
}

void	quit_table(t_data *context)
{
	int	i;

	i = 0;
	if (context && context->num_philo && context->philo)
	{
		while (i < context->num_philo)
		{
			memset(&context->philo[i], 0, sizeof(&context->philo));
			i++;
		}
		free(context->philo);
	}
	the_end(context);
}

/* FIXME : context->forks doesn't work ; how to fix ? l.57 */
void	clear_table(t_data *context)
{
	int	i;

	i = 0;
	if (context && context->num_philo && context->forks)
	{
		while (i < context->num_philo)
		{
			if (pthread_mutex_destroy(&context->forks[i]) != 0)
				printf("mutex detroy failed\n");
			i++;
		}
		free(context->forks);
		pthread_mutex_destroy(&context->mtx_meal);
		pthread_mutex_destroy(&context->mtx_write);
		pthread_mutex_destroy(&context->mtx_death);
	}
	quit_table(context);
}

/* FIXME : context->thrd doesn't work ; how to fix ? l.79 */
void	finish_diner(t_data *context)
{
	int	i;

	i = 0;
	if (context && context->num_philo && context->thrd != 0)
	{
		while (i < context->num_philo)
		{
			if (pthread_join (context->thrd[i], NULL) != 0)
				printf_error("pthread join");
			i++;
		}
		free(context->thrd);
	}
	clear_table(context);
}
