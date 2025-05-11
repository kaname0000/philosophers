# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okaname <okaname@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 20:36:55 by okaname           #+#    #+#              #
#    Updated: 2025/05/01 16:20:17 by okaname          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -pthread -g

MANDATORY = philo

SRCS =  print_error.c\
		set_philo.c\
		main.c\
		make_list.c\
		set_routine.c\
		get_time.c\
		write_time.c\
		check_death.c\
		check_all_full.c\
		free_list.c\
		pick_fork.c\
		only_philo.c\
		utils/isdigit.c\
		utils/putstr_fd.c\
		utils/putnbr.c\
		utils/putchar.c\

OBJS = $(SRCS:.c=.o)

all: $(MANDATORY)

$(MANDATORY): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
	
fclean: clean
	rm -f $(MANDATORY) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re