/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finisher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:15:36 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/02 02:03:14 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

// FIXME : Complete this function with all usages ;
void	usage(void)
{
	printf("\tUSAGE :\nLaunch : ./Philo <number_of_philosophers> <time_to_die>");
	printf(" <time_to_eat> <time_to_sleep>");
	printf(" <Optional:number_of_times_each_philosopher_must_eat>\n\n");
}

/* Add clean new mutex */
void	finish_diner(t_data *context)
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
	}
	i = 0;
	if (context && context->num_philo && context->philo)
	{
		while (i < context->num_philo)
		{
			memset(&context->philo[i], 0, sizeof(context->philo));
			i++;
		}
		free(context->philo);
	}
	the_end(context);
}

int	the_end(t_data *context)
{
	int	i;

	i = 0;
	if (context && context->num_philo && context->thrd)
	{
		while (i < context->num_philo)
		{
			if (pthread_join (context->thrd[i], NULL) != 0)
				printf_error("pthread join");
			i++;
		}
	}
	if (context)
	{
		memset(context, 0, sizeof(context));
		free (context);
		context = NULL;
	}
	exit (0);
	return (0);
}
