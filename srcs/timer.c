/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:59:21 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/01 20:24:23 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/* TODO : Count time function since start
	act_time - start_time = act_time ;
*/
int	time_counter()
{
	
}

long int	get_time(void)
{
	unsigned long		timestamp;
	struct timeval		time;

	timestamp = 0;
	if (gettimeofday(&time, NULL) != 0)
	{
		printf_error("couldn't get time");
		return (1);
	}
	timestamp = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (timestamp);
}
