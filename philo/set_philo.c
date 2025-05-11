/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:42:50 by okaname           #+#    #+#             */
/*   Updated: 2025/04/29 21:05:58 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	atoi_with_error(char *n, t_data *data)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (ft_isdigit(n[i]))
	{
		if ((num > (INT_MAX - (n[i] - '0')) / 10))
			data->error_flag = 1;
		num = num * 10 + (n[i++] - '0');
	}
	if (n[i] != '\0')
		data->error_flag = 1;
	return ((int)num);
}

static void	make_data(t_data *data, int argc, char **argv)
{
	data->error_flag = 0;
	data->number = atoi_with_error(argv[1], data);
	data->die = atoi_with_error(argv[2], data);
	data->eat = atoi_with_error(argv[3], data);
	data->sleep = atoi_with_error(argv[4], data);
	data->must_eat = -1;
	if (argc == 6)
		data->must_eat = atoi_with_error(argv[5], data);
}

t_philo	*set_philo(int argc, char **argv)
{
	t_philo	*head;
	t_data	data;

	make_data(&data, argc, argv);
	if (data.error_flag)
		return (NULL);
	head = make_list(data);
	if (head == NULL)
		return (NULL);
	return (head);
}
