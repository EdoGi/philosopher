/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:27:55 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/22 17:17:36 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TODO : GENERAL
	- Init all philo thread
	- Attribute all philo thread to realtive fork
	- Write function to get day time in UNIX time
	- Write funtion to clean all

	philo are thread ;
	they have relative forks(mutex);
	for each I do routine :
	
		routine
	each odd philo start eat for <time to eat>
		eat :
				-> they mutex lock the fork close to them
				-> eat the time needed
				-> unlock the mutex
				-> num_of_eat_this_philo += 1;
				-> count down time to eat start
	after eat ; they sleep for <time to sleep>
		sleep : 
				-> philo go to sleep the time needed
				-> philo wake up and start to think
	after sleep ; they start to think
		think :
				-> they think until the 2 forks attibuted are available
				-> the countdown <time to die> have to be checked
				-> if dead : EVERYTHING STOP ! => finish_diner with (cause of dead parameter)

*/

#include "../include/philosopher.h"

int	routine(t_philo *philo)
{
	// TODO : Create routine
	printf("Philo %d is thinking", philo->id);
	usleep(philo->ctxt->time_sleep);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	printf("Philo %d is eating", philo->id);
	usleep(philo->ctxt->time_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	printf("Philo %d is sleeping", philo->id);
	usleep(philo->ctxt->time_sleep);
}

int	init_context(int ac, char **av, t_data *context)
{
	memset(context, 0, sizeof(context));
	if (context_parse(ac, av, &context))
	{
		printf("Wrong Context !\n\n");
		usage();
		return (1);
	}
	if (pthread_mutex_init(&context->forks, NULL) != 0)
	{
		printf("mutex init failed\n");
		return (1);
	}
	return (0);
}

int	init_philo(int ac, char **av, t_data *context)
{

}

int	main(int ac, char **av)
{
	// FIXME : put thread inside t_data ?
	pthread_t		*thread;
	t_data			context;
	int				i;

	if (init_context(ac, av, &context))
	{
		printf("error : init context failed\n");
		return (finish_diner(&context));
	}
	// TODO : Init Pthread
	if (init_philo(ac, av, &thread))
	{
		printf("error : init thread failed\n");
		return (finish_diner(&context));
	}
	// FIXME : create to update
	i = 0;
	while (i < context.num_philo)
	{
		if (pthread_create(&thread[i], NULL, &routine, &context.philo[i]) != 0)
		{
			printf("error : pthread create");
		return (finish_diner(&context));
		}
		i++;
	}
	i = 0;
	// FIXME : join to update
	while (i < context.num_philo)
	{
		if (pthread_join (thread, NULL) != 0)
		{
			printf("error : pthread join");
		return (finish_diner(&context));
		}
	}
	finish_diner(&context);
	return (0);
}
