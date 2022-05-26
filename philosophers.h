/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:40:00 by atahiri           #+#    #+#             */
/*   Updated: 2022/05/26 14:02:16 by virsnp00x        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// typedef enum e_status {
// 	EATING,
// 	SLEEPING,
// 	THINKING,
// 	DEAD
// }			t_status;

typedef struct s_data
{
	int					num_of_philos;
	unsigned long long	start_time;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int                 it_must_eat;
	int					num_of_times_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
}				t_data;

typedef struct s_philo {
	// t_status			status;
	int					id;
	int					eat;
	t_data				*data;
	int					eats_counter;
	unsigned long long	last_eat;
	pthread_mutex_t		eat_mutex;
}				t_philo;

int					ft_atoi(const char *str);
int					ft_isdigit(int c);
t_philo				*init_philos(int argc, char **argv);
t_data  			*ft_convert_and_get_data(int argc, char **argv);
void 				ft_check_data_error(t_data *data, int argc);
int					ft_start(pthread_t	*threads, t_philo *philos);
void				ft_take_forks(t_philo *philo);
void				ft_start_eating(t_philo *philo);
void				ft_start_sleeping(t_philo *philo);
void				ft_start_thinking(t_philo *philo);
void				*ft_activities(void *data);
unsigned long long	timestamp(t_philo *philo);
void				myusleep(unsigned long long time);
unsigned long long	get_time(void);
void    			ft_print_message(int i, t_philo *philo);
void    			ft_errors_msg(int i);
void 				ft_display_msg(char *str);
#endif