/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:04:45 by okaname           #+#    #+#             */
/*   Updated: 2025/04/25 23:09:29 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_philo *philo)
{
	if (philo->data.die < (get_time_in_ms() - philo->last_meal_time))
	{
		*(philo->death_flag) = 1;
		return (write_time_died(philo), 1);
	}
	else
		return (0);
}
