/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:27:55 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/03 18:48:52 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TODO : GENERAL
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

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_data			context;

	if (init_context(ac, av, &context))
	{
		printf_error("initializer failed");
		return (the_end(&context));
	}
	while (context.itsok == 0)
		context.itsok = is_it_ok(&context);
	finish_diner(&context);
	return (0);
}
