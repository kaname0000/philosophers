/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:47:08 by okaname           #+#    #+#             */
/*   Updated: 2025/04/20 21:59:06 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	pick_forks(t_philo *arg)
{
	if (arg->philo_num % 2 == 1)
	{
		pthread_mutex_lock(arg->right_fork);
		write_time_fork(arg->philo_num, arg->start_time, arg->write);
		pthread_mutex_lock(arg->left_fork);
		write_time_fork(arg->philo_num, arg->start_time, arg->write);
	}
	else if (arg->philo_num % 2 == 0)
	{
		pthread_mutex_lock(arg->left_fork);
		write_time_fork(arg->philo_num, arg->start_time, arg->write);
		pthread_mutex_lock(arg->right_fork);
		write_time_fork(arg->philo_num, arg->start_time, arg->write);
	}
}

static void	eat(t_philo *arg)
{
	write_time_eat(arg->philo_num, arg->start_time, arg->write,
		&arg->last_meal_time);
	usleep(arg->data.eat * 1000);
	pthread_mutex_unlock(arg->right_fork);
	pthread_mutex_unlock(arg->left_fork);
}

static void	*routine(void *philo)
{
	t_philo	*arg;

	arg = (t_philo *)philo;
	while (1)
	{
		if (*(arg->death_flag) || check_death(arg))
			break ;
		pick_forks(arg);
		if (*(arg->death_flag) || check_death(arg))
			break ;
		eat(arg);
		if (*(arg->death_flag) || check_death(arg))
			break ;
		write_time_sleep(arg->philo_num, arg->start_time, arg->write);
		usleep(arg->data.sleep * 1000);
		if (*(arg->death_flag) || check_death(arg))
			break ;
		write_time_think(arg->philo_num, arg->start_time, arg->write);
	}
	*(arg->death_flag) = 1;
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
