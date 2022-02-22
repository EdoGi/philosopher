/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:21:36 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/22 18:51:40 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

// TODO : Parsing

int	parse_context(int ac, char **av, t_data *context)
{
	if (ac == 5 || ac == 6)
	{
		context->num_philo = ft_atoi(av[1]);
		context->time_die = ft_atoi(av[2]);
		context->time_eat = ft_atoi(av[3]);
		context->time_sleep = ft_atoi(av[4]);
		if (ac == 6)
			context->num_eat = ft_atoi(av[5]);
		return (0);
	}
	return (1);
}
