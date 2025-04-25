/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:19:23 by okaname           #+#    #+#             */
/*   Updated: 2025/04/25 23:15:13 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	write_time_fork(t_philo *arg)
{
	long	now_time;

	now_time = get_time_in_ms() - arg->start_time;
	if (*(arg->death_flag) || check_death(arg))
		return (1);
	pthread_mutex_lock(arg->write);
	printf("%ld %d has taken a fork\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
	return (0);
}

int	write_time_eat(t_philo *arg)
{
	arg->last_meal_time = get_time_in_ms();
	if (*(arg->death_flag) || check_death(arg))
		return (1);
	pthread_mutex_lock(arg->write);
	printf("%ld %d is eating\n", (arg->last_meal_time - arg->start_time),
		arg->philo_num);
	pthread_mutex_unlock(arg->write);
	return (0);
}

int	write_time_sleep(t_philo *arg)
{
	long	now_time;

	now_time = get_time_in_ms() - arg->start_time;
	if (*(arg->death_flag) || check_death(arg))
		return (1);
	pthread_mutex_lock(arg->write);
	printf("%ld %d is sleeping\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
	return (0);
}

int	write_time_think(t_philo *arg)
{
	long	now_time;

	now_time = get_time_in_ms() - arg->start_time;
	if (*(arg->death_flag) || check_death(arg))
		return (1);
	pthread_mutex_lock(arg->write);
	printf("%ld %d is thinking\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
	return (0);
}

void	write_time_died(t_philo *arg)
{
	long	now_time;

	now_time = get_time_in_ms() - arg->start_time;
	pthread_mutex_lock(arg->write);
	printf("%ld %d died\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
}
