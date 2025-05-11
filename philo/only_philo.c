/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:13:58 by okaname           #+#    #+#             */
/*   Updated: 2025/05/01 16:15:15 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	only_philo(t_philo *arg)
{
	pthread_mutex_lock(arg->right_fork);
	write_time_fork(arg);
	usleep(arg->data.die * 1000);
	write_time_died(arg);
	pthread_mutex_unlock(arg->right_fork);
	return (1);
}
