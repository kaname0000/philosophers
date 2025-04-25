/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:09:26 by okaname           #+#    #+#             */
/*   Updated: 2025/04/26 03:35:01 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_philo	*make_node(t_data data, int philo_num)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->right_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philo->right_fork == NULL)
		return (free(philo), NULL);
	pthread_mutex_init(philo->right_fork, NULL);
	philo->philo_num = philo_num + 1;
	philo->data = data;
	philo->eat_count = 0;
	philo->left_fork = NULL;
	philo->right = NULL;
	philo->left = NULL;
	return (philo);
}

static void	free_list2(t_philo *list, int qty)
{
	int		i;
	t_philo	*tmp;

	if (!list)
		return ;
	i = 0;
	while (i < qty)
	{
		tmp = list;
		list = list->right;
		pthread_mutex_destroy(tmp->right_fork);
		free(tmp->right_fork);
		free(tmp);
		i++;
	}
}

static t_philo	*share_write_death_flag(t_philo *philo)
{
	t_philo	*tmp;
	int		i;
	int		num;

	philo->write = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philo->write == NULL)
		return (NULL);
	philo->death_flag = (int *)malloc(sizeof(int));
	if (philo->death_flag == NULL)
		return (free(philo->write), NULL);
	pthread_mutex_init(philo->write, NULL);
	*(philo->death_flag) = 0;
	i = 0;
	num = philo->data.number;
	tmp = philo;
	while (i < num)
	{
		tmp->right->write = tmp->write;
		tmp->right->death_flag = tmp->death_flag;
		tmp = tmp->right;
		i++;
	}
	return (tmp);
}

static t_philo	*share_fork(t_philo *philo)
{
	t_philo	*tmp;
	int		i;

	tmp = share_write_death_flag(philo);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < philo->data.number)
	{
		tmp->right->left_fork = tmp->right_fork;
		tmp = tmp->right;
		i++;
	}
	return (philo);
}

t_philo	*make_list(t_data data)
{
	t_philo	*head;
	t_philo	*tmp;
	t_philo	*new_node;
	int		i;

	i = 0;
	head = make_node(data, i);
	if (head == NULL)
		return (NULL);
	tmp = head;
	while (++i < data.number)
	{
		new_node = make_node(data, i);
		if (new_node == NULL)
			return (free_list2(head, i), NULL);
		tmp->right = new_node;
		new_node->left = tmp;
		tmp = tmp->right;
	}
	tmp->right = head;
	head->left = tmp;
	return (share_fork(head));
}
