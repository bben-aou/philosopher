/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:16:43 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/05/26 18:02:52 by virsnp00x        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_print_message(int i, t_philo *philo)
{
    pthread_mutex_lock(&philo->data->print_mutex);
    if (i == 0)
        printf("⌛ \033[0;44m%lld\033[0m ⌛ \033[0;33mphilosopher  👴 %d has taken a fork\033[0m 🍴\n",timestamp(philo), philo->id + 1);
    else if (i == 1) 
        printf("⌛ \033[0;44m%lld\033[0m ⌛ \033[0;35mphilosopher   👴 %d is eating \033[0m  🍝\n",timestamp(philo), philo->id + 1);
    else if (i == 2)
        printf("⌛ \033[0;44m%lld\033[0m ⌛  \033[0;34mphilosopher  👴 %d is sleeping \033[0m  😴 \n",timestamp(philo), philo->id + 1);
    else if (i == 3)
         printf("⌛ \033[0;44m%lld\033[0m ⌛ \033[0;31mphilosopher  👴 %d is thinking  🤔 \033[0m\n",timestamp(philo), philo->id + 1);
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

