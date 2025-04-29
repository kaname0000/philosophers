/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:26:49 by okaname           #+#    #+#             */
/*   Updated: 2025/04/29 21:11:31 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "utils/utils.h"
# include <ctype.h>
# include <limits.h>
# include <pthread.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				number;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				error_flag;
}					t_data;

typedef struct s_philo
{
	int				philo_num;
	t_data			data;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*write;
	pthread_t		thread;
	long			start_time;
	long			last_meal_time;
	int				*death_flag;
	int				eat_count;
	struct s_philo	*right;
	struct s_philo	*left;
}					t_philo;

void				print_error(void);
t_philo				*set_philo(int argc, char **argv);
void				free_list(t_philo *list);
t_philo				*make_list(t_data data);
int					set_routine(t_philo *philo);
long				get_time_in_ms(void);
int					write_time_fork(t_philo *arg);
int					write_time_eat(t_philo *arg);
int					write_time_sleep(t_philo *arg);
int					write_time_think(t_philo *arg);
void				write_time_died(t_philo *arg);
int					check_death(t_philo *philo);
int					check_all_full(t_philo *philo);
int					pick_right_fork(t_philo *philo);
int					pick_left_fork(t_philo *philo);

#endif
