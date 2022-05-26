/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:17:06 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/05/26 15:17:07 by virsnp00x        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"

unsigned long long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	myusleep(unsigned long long time)
{
	// unsigned long long	current_time;

	// current_time = get_time();
	// usleep((time * 1e3) - 10000);
	// while (get_time() - current_time < time)
	// 	continue ;
	unsigned long long  end;
	end = get_time() + time;
	while (get_time() < end)
		usleep(time / 1000);
}

unsigned long long	timestamp(t_philo *philo)
{
	return (get_time() - philo->data->start_time);
}
