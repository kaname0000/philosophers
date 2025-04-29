/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:09:19 by okaname           #+#    #+#             */
/*   Updated: 2025/04/29 21:12:56 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	pick_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (write_time_fork(philo))
		return (pthread_mutex_unlock(philo->right_fork), 1);
	else
		return (0);
}

int	pick_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (write_time_fork(philo))
		return (pthread_mutex_unlock(philo->left_fork), 1);
	else
		return (0);
}
