/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:21:36 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/23 12:54:15 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	printf_errors(char *str)
{
	printf("%sERROR: %s\n%s", RED_BLINK, str, RESET);
}

int	parse_error(int ac, char **av)
{
	int	i;
	int	num;

	i = 1;
	while (i <= ac)
	{
		if (ft_isnumber(av[i]))
		{
			printf("=> %s is not a digit\n", av[i]);
			return (1);
		}
		num = ft_atoi(av[i]);
		if (num > INT_MAX || num < 0 || ft_strlen(av[i]) > 11)
		{
			printf("=> %s is not a wrong digit\n", av[i]);
			return (1);
		}
	}
	return (0);
}

// FIXME : What todo if num_eat == 0 ?
int	parse_context(int ac, char **av, t_data *context)
{
	if (ac == 5 || ac == 6)
	{
		if (parse_error(ac, av))
			return (1);
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
