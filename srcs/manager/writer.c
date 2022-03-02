/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:30:42 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/02 00:45:00 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	writer(char *emoji, char *txt, t_philo *philo, t_data *context)
{
	long int	timestamp;

	timestamp = get_time() - context->start;
	if (context->itsok == 0)
		printf("%s %d ms : Philo %d %s", emoji, timestamp, philo->id, txt);
}
