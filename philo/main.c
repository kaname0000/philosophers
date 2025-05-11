/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:26:26 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 15:34:51 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// static void	print_data(t_philo *philo)
// {
// 	printf("%d\n", philo->data.die);
// 	printf("%d\n", philo->data.eat);
// 	printf("%d\n", philo->data.number);
// 	printf("%d\n", philo->data.sleep);
// }

static void	wait_routine(t_philo *philo)
{
	t_philo	*tmp;
	int		i;
	int		num;

	tmp = philo;
	i = 0;
	num = philo->data.number;
	while (i < num)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->right;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_philo	*head;

	if (!(argc == 5 || argc == 6))
	{
		print_error();
		return (1);
	}
	head = set_philo(argc, argv);
	if (head == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	set_routine(head);
	wait_routine(head);
	free_list(head);
	return (0);
}
