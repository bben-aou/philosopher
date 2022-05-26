/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:39:28 by atahiri           #+#    #+#             */
/*   Updated: 2022/05/26 14:06:39 by virsnp00x        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void    ft_check_data(int argc, char **argv)
{
    int	i;
	int	j;

	i = 0;
	if (argc != 5 && argc != 6)
		ft_errors_msg(1);
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				ft_errors_msg(1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	pthread_t	*threads;
	// int			i;

	// if (error_handling(argc, argv))
	// {
	// 	printf("Error in arguments\n");
	// 	return (1);
	// }
	// else
	ft_check_data(argc, argv) ;
	philos = init_philos(argc, argv);
	if (!(philos))
        ft_errors_msg(8);
	threads = malloc(sizeof(pthread_t) * philos->data->num_of_philos);
	// i = -1;
	// while (++i < philos->state->philos_nb)
	// 	pthread_mutex_init(&philos->state->forks[i], NULL);
	if (ft_start(threads, philos) == 0)
		return (0);
	return (0);
}
