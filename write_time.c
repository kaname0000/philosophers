/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:19:23 by okaname           #+#    #+#             */
/*   Updated: 2025/04/24 22:55:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_time_fork(t_philo *arg)
{
	long	now_time;

	now_time = get_time_in_ms() - arg->start_time;
	if (*(arg->death_flag) || check_death(arg))
			return ;
	pthread_mutex_lock(arg->write);
	printf("%ld %d has taken a fork\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
}

void	write_time_eat(t_philo *arg)
{
	arg->last_meal_time = get_time_in_ms();
	pthread_mutex_lock(arg->write);
	if (*(arg->death_flag) || check_death(arg))
			return ;
	printf("%ld %d is eating\n", (arg->last_meal_time - arg->start_time), arg->philo_num);
	pthread_mutex_unlock(arg->write);
}

void	write_time_sleep(t_philo* arg)
{
	long	now_time;

	now_time = get_time_in_ms() - arg->start_time;
	pthread_mutex_lock(arg->write);
	printf("%ld %d is sleeping\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
}

void	write_time_think(t_philo* arg)
{
	long	now_time;

	now_time = get_time_in_ms() - arg->start_time;
	pthread_mutex_lock(arg->write);
	printf("%ld %d is thinking\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
}

void	write_time_died(t_philo* arg)
{
	long	now_time;

	now_time = get_time_in_ms() - arg->start_time;
	pthread_mutex_lock(arg->write);
	printf("%ld %d died\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
}
