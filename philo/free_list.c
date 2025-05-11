/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:56:47 by okaname           #+#    #+#             */
/*   Updated: 2025/04/26 03:59:37 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_list(t_philo *list)
{
	t_philo	*current;
	t_philo	*tmp;

	if (!list)
		return ;
	current = list;
	tmp = current->right;
	pthread_mutex_destroy(current->write);
	free(current->write);
	free(current->death_flag);
	while (tmp != list)
	{
		pthread_mutex_destroy(current->right_fork);
		free(current->right_fork);
		free(current);
		current = tmp;
		tmp = current->right;
	}
	pthread_mutex_destroy(current->right_fork);
	free(current->right_fork);
	free(current);
}
