/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:27:24 by atahiri           #+#    #+#             */
/*   Updated: 2022/05/26 13:39:51 by virsnp00x        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_activities(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		ft_take_forks(philo);
		ft_start_eating(philo);
		ft_start_sleeping(philo);
		ft_start_thinking(philo);
	}
	return (NULL);
}

int	ft_check_number_of_eatings(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->num_of_philos)
	{
		if (philos->data->it_must_eat > philos[i].eats_counter)
			return (0);
	}
	return (1);
}

void	*ft_watcher(void *philos)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)philos;
	usleep(100);
	while (1)
	{
		i = -1;
		while (++i < philo[0].data->num_of_philos)
		{
			if ((get_time() - philo[i].last_eat) > philo[i].data->time_to_die
				&& !philo[i].eat)
			{
				pthread_mutex_lock(&philo[i].eat_mutex);
				pthread_mutex_lock(&philo->data->print_mutex);
				printf("%lld %d dead\n", timestamp(philo), philo->id + 1);
				pthread_mutex_unlock(&philo[i].eat_mutex);
				return (NULL);
			}
		}
		if (philo->data->it_must_eat == 1 && ft_check_number_of_eatings(philos))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

int	ft_start(pthread_t *threads, t_philo *philos)
{
	pthread_t	wathcher_thread;
	int			i;

	i = -1;
	while (++i < philos->data->num_of_philos)
	{
		if (i == 0)
			philos->data->start_time = get_time();
		pthread_create(&threads[i], NULL, &ft_activities, (void *)&philos[i]);
		usleep(1);
	}
	pthread_create(&wathcher_thread, NULL, ft_watcher, (void *)philos);
	pthread_join(wathcher_thread, NULL);
	return (1);
}
