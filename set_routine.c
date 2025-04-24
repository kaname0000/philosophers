/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:47:08 by okaname           #+#    #+#             */
/*   Updated: 2025/04/24 22:51:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	pick_forks(t_philo *arg)
{
	if (arg->philo_num % 2 == 1)
	{
		pthread_mutex_lock(arg->right_fork);
		if (*(arg->death_flag) || check_death(arg))
			return ;
		write_time_fork(arg);
		pthread_mutex_lock(arg->left_fork);
		if (*(arg->death_flag) || check_death(arg))
			return ;
		write_time_fork(arg);
	}
	else if (arg->philo_num % 2 == 0)
	{
		pthread_mutex_lock(arg->left_fork);
		if (*(arg->death_flag) || check_death(arg))
			return ;
		write_time_fork(arg);
		pthread_mutex_lock(arg->right_fork);
		if (*(arg->death_flag) || check_death(arg))
			return ;
		write_time_fork(arg);
	}
}

static void	eat(t_philo *arg)
{
	write_time_eat(arg);
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
		write_time_sleep(arg);
		usleep(arg->data.sleep * 1000);
		if (*(arg->death_flag) || check_death(arg))
			break ;
		write_time_think(arg);
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
