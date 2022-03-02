/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:05:51 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/23 12:50:40 by egiacomi         ###   ########.fr       */
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
	while (!ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] && !ft_isdigit(nptr[i]))
	{
		ret = ret * 10 + (nptr[i] - '0');
		i++;
	}
	if (ret > 9223372036854775807)
		return (-1);
	return (ret * sign);
}

int	ft_isnumber(char *nbr)
{
	int	i;

	i = 0;
	while (!ft_isspace(nbr[i]))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		if (ft_isdigit(nbr[i]))
			return (1);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	ft_isspace(int c)
{
	if (((signed)c >= 9 && (signed)c <= 13) || (signed)c == 32)
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
