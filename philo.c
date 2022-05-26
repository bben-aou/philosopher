/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:16:18 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/05/26 17:33:16 by virsnp00x        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

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

	ft_check_data(argc, argv) ;
	philos = init_philos(argc, argv);
	if (!(philos))
        ft_errors_msg(8);
	threads = malloc(sizeof(pthread_t) * philos->data->num_of_philos);
	if (ft_start(threads, philos) == 0)
		return (0);
	return (0);
}
