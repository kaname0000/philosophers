/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:29:32 by okaname           #+#    #+#             */
/*   Updated: 2025/04/20 15:31:00 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_error(void)
{
	ft_putstr_fd("number_of_philosophers time_to_die", 2);
	ft_putstr_fd(" time_to_eat time_to_sleep\n", 2);
	ft_putstr_fd("[number_of_times_each_philosopher_must_eat]\n", 2);
}
