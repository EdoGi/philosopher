/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:27:55 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/19 20:17:36 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

// TODO : init forks as mutex
static pthread_mutex_t mutex_stock = PTHREAD_MUTEX_INITIALIZER;

int	routine(void)
{
	// TODO : Create routine
}

int	main(int ac, char **av)
{
	pthread_t	*philo;
	t_data		context;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	// TODO : Init Pthread
	// FIXME : create to clean
	while (i < ft_atoi(av[1]))
	{
		ret = pthread_create(&philo[i], NULL, &routine, NULL);
		if (ret != 0)
		{
			printf("error : pthread create");
			finish_diner();
		}
	}
	i = 0;
	// FIXME : join to clean
	while (i < ft_atoi(av[1]))
	{
		ret = pthread_join (philo, &context);
		if (ret != 0)
		{
			printf("error : pthread create");
			finish_diner();
		}
	}
	finish_diner();
}
