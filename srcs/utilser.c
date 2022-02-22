/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:05:51 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/22 19:43:37 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		ret = ret * 10 + (nptr[i] - '0');
		i++;
	}
	if (ret > 9223372036854775807)
		return (-1);
	return (ret * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (((signed)c >= 9 && (signed)c <= 13) || (signed)c == 32)
		return (1);
	return (0);
}

void	printf_errors(char *str)
{
	printf("%sERROR: %s\n%s", RED_BLINK, str, RESET);
}
