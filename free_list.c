/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:56:47 by okaname           #+#    #+#             */
/*   Updated: 2025/04/20 17:43:29 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_list(t_philo *list)
{
	t_philo	*tmp;
	t_philo	*current;

	if (list == NULL)
		return ;
	current = list;
	pthread_mutex_destroy(current->write);
	if (current->right == current)
	{
		pthread_mutex_destroy(current->right);
		free(current);
		list = NULL;
		return ;
	}
	while (current->right != list)
	{
		tmp = current->right;
		pthread_mutex_destroy(current->right);
		free(current);
		current = tmp;
	}
	free(current);
	list = NULL;
}
