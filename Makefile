# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 11:07:12 by pllucian          #+#    #+#              #
#    Updated: 2021/11/22 01:49:17 by pllucian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =	push_swap.c \
		algoritm.c \
		move_to_a.c \
		move_to_b.c \
		operations.c \
		utils_sort.c \
		utils_get.c \
		utils.c

FILES_BONUS =	checker.c \
				checker_parser.c \
				checker_opers.c \
				checker_utils.c

SRCS_BONUS = $(addprefix srcs/, $(FILES_BONUS))

SRCS = $(addprefix srcs/, $(FILES))

OBJS = $(addprefix objs/, $(FILES:.c=.o))

OBJS_BONUS = $(addprefix objs/, $(FILES_BONUS:.c=.o))

INCL = includes/push_swap.h

INCL_BONUS = includes/checker.h

NAME = push_swap

NAME_BONUS = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

objs/%.o:		srcs/%.c
				@ [ -d objs ] || mkdir -p objs
				$(CC) $(CFLAGS) -c $< -o $@ -I./includes -I./libft/includes

$(NAME):		$(OBJS) $(INCL)
				@make -C ./libft
				$(CC) -o $@ $(OBJS) -Llibft -lft

$(NAME_BONUS):	$(OBJS_BONUS) $(INCL_BONUS)
				@make -C ./libft
				$(CC) -o $@ $(OBJS_BONUS) -Llibft -lft

bonus:			$(NAME) $(NAME_BONUS)

all:			$(NAME) $(NAME_BONUS)

clean:
				make clean -C ./libft
				$(RM)r $(OBJS) $(OBJS_BONUS) objs

fclean:			clean
				make fclean -C ./libft
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

n ?= 2

test:
			@ ARG=`ruby -e "puts (1..$(n)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG
			@ ARG=`ruby -e "puts (1..$(n)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG
			@ ARG=`ruby -e "puts (1..$(n)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG
			@ ARG=`ruby -e "puts (1..$(n)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG
			@ ARG=`ruby -e "puts (1..$(n)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG
			@ ARG=`ruby -e "puts (1..$(n)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG
			@ ARG=`ruby -e "puts (1..$(n)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG
			@ ARG=`ruby -e "puts (1..$(n)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG
			@ ARG=`ruby -e "puts (1..$(n)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG
			@ ARG=`ruby -e "puts (1..$(n)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG

.PHONY:		bonus all clean fclean re test
