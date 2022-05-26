/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:16:52 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/05/26 15:16:54 by virsnp00x        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data  *ft_convert_and_get_data(int argc, char **argv)
{
    t_data  *data;

    data = (t_data *)malloc(sizeof(t_data));
    data->num_of_philos = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->it_must_eat = 0;
    data->num_of_times_eat = 0;
    if (argc == 6)
    {
        data->it_must_eat = 1;
        data->num_of_times_eat = ft_atoi(argv[5]); 
    }
    return (data);
}

void ft_check_data_error(t_data *data, int argc)
{
    if (data->num_of_philos <= 0)
        ft_errors_msg(2);
    if (data-> time_to_sleep <= 0)
        ft_errors_msg(3);
    if (data->time_to_eat <= 0)
        ft_errors_msg(4);
    if (data->time_to_die <= 0)
        ft_errors_msg(5);
    if (data->num_of_times_eat <= 0 && argc == 6)
        ft_errors_msg(6);
}


t_philo	*init_philos(int argc, char **argv)
{
	t_philo			*philos;
	t_data			*data;
	int				i;

	data = ft_convert_and_get_data(argc, argv);
	ft_check_data_error(data, argc);
	data->forks =(pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	i = -1;
	while (++i < data->num_of_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	philos = malloc(sizeof(t_philo) * data->num_of_philos);
	i = -1;
	while (++i < data->num_of_philos)
	{
		philos[i].id = i;
		philos[i].data = data;
		philos[i].eat = 0;
		philos[i].eats_counter = 0;
		philos[i].last_eat = get_time();
		pthread_mutex_init(&philos[i].eat_mutex, NULL);
	}
	return (philos);
}
