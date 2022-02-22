/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finisher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:15:36 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/22 15:08:50 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

// FIXME : Complete this function with all usages ;
void	usage(void)
{
	printf("\tUSAGE :\nLaunch : ./Philo <number_of_philosophers> <time_to_die>");
	printf(" <time_to_eat> <time_to_sleep>");
	printf(" <Optional:number_of_times_each_philosopher_must_eat>\n\n");
}

void	finish_diner(t_data *context)
{
	if (pthread_mutex_destroy(&context->forks) != 0)
		printf("mutex detroy failed\n");
}
