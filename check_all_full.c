/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 03:28:41 by okaname           #+#    #+#             */
/*   Updated: 2025/04/26 03:34:48 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_all_full(t_philo *philo)
{
	t_philo	*tmp;
	int		i;

	tmp = philo;
	i = 0;
	while (i < tmp->data.number)
	{
		if (tmp->eat_count < tmp->data.must_eat)
			return (0);
		tmp = tmp->right;
		i++;
	}
	*(philo->death_flag) = 1;
	return (1);
}
