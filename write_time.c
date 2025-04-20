/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:19:23 by okaname           #+#    #+#             */
/*   Updated: 2025/04/20 22:18:23 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_time_fork(int num, long start_time, pthread_mutex_t *write)
{
	long	now_time;

	now_time = get_time_in_ms() - start_time;
	pthread_mutex_lock(write);
	printf("%ld %d has taken a fork\n", now_time, num);
	pthread_mutex_unlock(write);
}

void	write_time_eat(int num, long start_time, pthread_mutex_t *write,
		long *last_meal_time)
{
	*last_meal_time = get_time_in_ms();
	pthread_mutex_lock(write);
	printf("%ld %d is eating\n", (*last_meal_time - start_time), num);
	pthread_mutex_unlock(write);
}

void	write_time_sleep(int num, long start_time, pthread_mutex_t *write)
{
	long	now_time;

	now_time = get_time_in_ms() - start_time;
	pthread_mutex_lock(write);
	printf("%ld %d is sleeping\n", now_time, num);
	pthread_mutex_unlock(write);
}

void	write_time_think(int num, long start_time, pthread_mutex_t *write)
{
	long	now_time;

	now_time = get_time_in_ms() - start_time;
	pthread_mutex_lock(write);
	printf("%ld %d is thinking\n", now_time, num);
	pthread_mutex_unlock(write);
}

void	write_time_died(int num, long start_time, pthread_mutex_t *write)
{
	long	now_time;

	now_time = get_time_in_ms() - start_time;
	pthread_mutex_lock(write);
	printf("%ld %d died\n", now_time, num);
	pthread_mutex_unlock(write);
}
