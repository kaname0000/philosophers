/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:47:08 by okaname           #+#    #+#             */
/*   Updated: 2025/04/25 23:22:30 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	pick_forks(t_philo *arg)
{
	if (arg->philo_num % 2 == 1)
	{
		pthread_mutex_lock(arg->right_fork);
		if (write_time_fork(arg))
			return (pthread_mutex_unlock(arg->right_fork), 1);
		pthread_mutex_lock(arg->left_fork);
		if (write_time_fork(arg))
			return (pthread_mutex_unlock(arg->left_fork), 1);
	}
	else if (arg->philo_num % 2 == 0)
	{
		pthread_mutex_lock(arg->left_fork);
		if (write_time_fork(arg))
			return (pthread_mutex_unlock(arg->left_fork), 1);
		pthread_mutex_lock(arg->right_fork);
		if (write_time_fork(arg))
			return (pthread_mutex_unlock(arg->right_fork), 1);
	}
	return (0);
}

static int	eat(t_philo *arg)
{
	pthread_mutex_unlock(arg->right_fork);
	pthread_mutex_unlock(arg->left_fork);
	if (write_time_eat(arg))
		return (1);
	usleep(arg->data.eat * 1000);
	return (0);
}

static void	*routine(void *philo)
{
	t_philo	*arg;

	arg = (t_philo *)philo;
	while (1)
	{
		if (pick_forks(arg))
			break ;
		if (eat(arg))
			break ;
		if (write_time_sleep(arg))
			break ;
		usleep(arg->data.sleep * 1000);
		if (write_time_think(arg))
			break ;
	}
	return (NULL);
}

static void	set_start_time(t_philo *philo)
{
	t_philo	*tmp;
	int		i;
	int		num;
	long	time;

	i = 0;
	num = philo->data.number;
	time = get_time_in_ms();
	tmp = philo;
	while (i < num)
	{
		tmp->start_time = time;
		tmp->last_meal_time = time;
		tmp = tmp->right;
		i++;
	}
}

int	set_routine(t_philo *philo)
{
	int		i;
	int		num;
	t_philo	*tmp;

	i = 0;
	num = philo->data.number;
	set_start_time(philo);
	tmp = philo;
	while (i < num)
	{
		if (pthread_create(&tmp->thread, NULL, routine, tmp) != 0)
			return (1);
		tmp = tmp->right;
		i++;
	}
	return (0);
}
