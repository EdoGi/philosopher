/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:27:55 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/01 21:58:48 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TODO : GENERAL
	- Init all philo thread
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

// TODO : Check why I have to write all path to include
#include "../include/philosopher.h"

// FIXME : update my join thread : l.75
int	main(int ac, char **av)
{
	t_data			context;

	if (init_context(ac, av, &context))
	{
		printf_error("initializer failed");
		return (the_end(&context));
	}
	finish_diner(&context);
	return (0);
}
