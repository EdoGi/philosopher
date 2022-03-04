/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:30:42 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/04 18:58:40 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	writer(char *emoji, char *txt, t_philo *philo, t_data *context)
{
	long int	timestamp;

	timestamp = get_time() - context->start;
	if (!check_ok(philo))
	{
		pthread_mutex_lock(&context->mtx_write);
		printf("%s %ld ms : Philo %d %s\n", emoji, timestamp, philo->id, txt);
		pthread_mutex_unlock(&context->mtx_write);
	}
}
