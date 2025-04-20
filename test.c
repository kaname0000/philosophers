/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:14:34 by okaname           #+#    #+#             */
/*   Updated: 2025/04/20 16:51:28 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000));
}

int	main(void)
{
	long	start;
	long	end;

	start = get_time_in_ms();
	usleep(500000);
	end = get_time_in_ms();
	printf("経過時間: %ldms\n", end - start);
	return (0);
}
