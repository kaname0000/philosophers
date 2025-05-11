/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:19:23 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 16:07:10 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	write_time_fork(t_philo *arg)
{
	long	now_time;

	if (check_death(arg))
		return (1);
	pthread_mutex_lock(arg->write);
	now_time = get_time_in_ms() - arg->start_time;
	if (*(arg->death_flag))
		return (pthread_mutex_unlock(arg->write), 1);
	printf("%ld %d has taken a fork\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
	return (0);
}

int	write_time_eat(t_philo *arg)
{
	if (check_death(arg))
		return (1);
	pthread_mutex_lock(arg->write);
	arg->last_meal_time = get_time_in_ms();
	if (*(arg->death_flag))
		return (pthread_mutex_unlock(arg->write), 1);
	printf("%ld %d is eating\n", (arg->last_meal_time - arg->start_time),
		arg->philo_num);
	pthread_mutex_unlock(arg->write);
	return (0);
}

int	write_time_sleep(t_philo *arg)
{
	long	now_time;

	if (check_death(arg))
		return (1);
	if (check_death(arg))
		return (1);
	pthread_mutex_lock(arg->write);
	now_time = get_time_in_ms() - arg->start_time;
	if (*(arg->death_flag))
		return (pthread_mutex_unlock(arg->write), 1);
	printf("%ld %d is sleeping\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
	return (0);
}

int	write_time_think(t_philo *arg)
{
	long	now_time;

	if (check_death(arg))
		return (1);
	pthread_mutex_lock(arg->write);
	now_time = get_time_in_ms() - arg->start_time;
	if (*(arg->death_flag))
		return (pthread_mutex_unlock(arg->write), 1);
	printf("%ld %d is thinking\n", now_time, arg->philo_num);
	pthread_mutex_unlock(arg->write);
	return (0);
}

void	write_time_died(t_philo *arg)
{
	long	now_time;

	pthread_mutex_lock(arg->write);
	now_time = get_time_in_ms() - arg->start_time;
	if (*(arg->death_flag))
		return (pthread_mutex_unlock(arg->write), (void)0);
	printf("%ld %d died\n", now_time, arg->philo_num);
	*(arg->death_flag) = 1;
	pthread_mutex_unlock(arg->write);
}
