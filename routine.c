/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:06:55 by atahiri           #+#    #+#             */
/*   Updated: 2022/05/26 15:09:21 by virsnp00x        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_print_message(int i, t_philo *philo)
{
    pthread_mutex_lock(&philo->data->print_mutex);
    if (i == 0)
        printf("%lld  %d has taken a fork\n",timestamp(philo), philo->id + 1);
    else if (i == 1)
        printf("%lld %d is eating \n",timestamp(philo), philo->id + 1);
    else if (i == 2)
        printf("%lld %d is sleeping \n",timestamp(philo), philo->id + 1);
    else if (i == 3)
         printf("%lld %d is thinking \n",timestamp(philo), philo->id + 1);
    if (i != 4)
        pthread_mutex_unlock(&philo->data->print_mutex);
}


void	ft_take_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(
			&philo->data->forks[(philo->id + 1) % philo->data->num_of_philos]);
		ft_print_message(0, philo);
		pthread_mutex_lock(&philo->data->forks[philo->id]);
		ft_print_message(0, philo);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->id]);
		ft_print_message(0, philo);
		pthread_mutex_lock(
			&philo->data->forks[(philo->id + 1) % philo->data->num_of_philos]);
		ft_print_message(0, philo);
	}
}

void	ft_start_eating(t_philo *philo)
{
	philo->eat = 1;
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat = get_time();
	ft_print_message(1, philo);
	myusleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->eat_mutex);
	philo->eats_counter += 1;
	philo->eat = 0;
	pthread_mutex_unlock(
		&philo->data->forks[(philo->id + 1) % philo->data->num_of_philos]);
	pthread_mutex_unlock(&philo->data->forks[philo->id]);
}

void	ft_start_sleeping(t_philo *philo)
{
	ft_print_message(2, philo);
	myusleep(philo->data->time_to_sleep);
}

void	ft_start_thinking(t_philo *philo)
{
	ft_print_message(3, philo);
}

