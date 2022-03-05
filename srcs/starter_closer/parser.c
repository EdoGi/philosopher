/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:21:36 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/05 03:45:36 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	printf_error(char *str)
{
	printf("%sERROR:%s %s\n%s", RED_BLINK, RESET, str, RESET);
}

int	parse_error(int ac, char **av)
{
	int	i;
	int	num;

	i = 1;
	while (i < ac)
	{
		if (ft_isnumber(av[i]))
		{
			printf("=> %s is not a digit\n", av[i]);
			return (1);
		}
		num = ft_atoi(av[i]);
		if (num > INT_MAX || num <= 0 || ft_strlen(av[i]) >= 11)
		{
			printf("=> %s is a wrong digit\n", av[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

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
		context->num_eat = 0;
		context->end = 0;
		if (ac == 6)
		{
			if (ft_atoi(av[5]) <= 0)
			{
				printf("Philosophers needs to eat at least once. \
					It's better for the moral.\n");
				return (1);
			}
			context->num_eat = ft_atoi(av[5]);
		}
		return (0);
	}
	return (1);
}
