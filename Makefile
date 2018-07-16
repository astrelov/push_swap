# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/14 20:54:44 by astrielov         #+#    #+#              #
#    Updated: 2018/07/15 14:19:21 by null             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = 			checker
PUSH_SWAP = 		push_swap

CFLAGS = 			-Wall -Wextra -Werror

HEADERS = 			-I ./includes

OBJDIR = 			obj/

CHECKER_SRC =		src/checker.c

PS_SRC =			src/push_swap.c \
					src/movers/moving_nbrs_to_b.c \
					src/movers/moving_nbrs_to_a.c \
					src/movers/finders_for_moving_to_a.c \
					src/movers/moving_nbrs_to_a_2.c \
					src/movers/three_nbrs_in_stack_a.c \
					src/movers/finders.c \
					src/movers/mr_cleaner.c \
					src/operations/p_s_op_handler.c

SHARED_SRC =		src/list/lst_new_node.c \
					src/list/lst_push.c \
					src/list/lst_pop.c \
					src/list/lst_create.c \
					src/list/lst_push_head.c \
					src/list/lst_is_sorted.c \
					src/list/lst_shift.c \
					src/list/lst_splice.c \
					src/operations/s.c \
					src/operations/p.c \
					src/operations/r.c \
					src/operations/rr.c \
					src/movers/shared_ps_checker.c

PS_OBJS = 			$(patsubst src/%.c, $(OBJDIR)%.o, $(PS_SRC))
PS_OBJS += 			$(patsubst src/%.c, $(OBJDIR)%.o, $(SHARED_SRC))

CHECKER_OBJS = 		$(patsubst src/%.c, $(OBJDIR)%.o, $(CHECKER_SRC))
CHECKER_OBJS += 	$(patsubst src/%.c, $(OBJDIR)%.o, $(SHARED_SRC))

all:
					@make --directory=./libft
					@make $(CHECKER)
					@make $(PUSH_SWAP)

$(CHECKER):			$(CHECKER_OBJS)
					@gcc $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS) -L ./libft -lft
					@printf "\033[0;32mchecker: DONE\033[0m\n"

$(PUSH_SWAP):		$(PS_OBJS)
					@gcc $(CFLAGS) -o $(PUSH_SWAP) $(PS_OBJS) -L ./libft -lft
					@printf "\033[0;32mpush_swap: DONE\033[0m\n"

$(CHECKER_OBJS):	| objdir

objdir:
					@mkdir -p $(OBJDIR)/list
					@mkdir -p $(OBJDIR)/movers
					@mkdir -p $(OBJDIR)/operations

$(OBJDIR)%.o:		src/%.c
					@gcc $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
					@rm -rf $(CHECKER_OBJS)
					@rm -rf $(PS_OBJS)
					@rm -rf $(OBJDIR)
					@make --directory=./libft clean
					@printf "\033[0;32mclean: DONE\033[0m\n"

fclean:
					@rm -rf $(CHECKER_OBJS)
					@rm -rf $(PS_OBJS)
					@rm -rf $(OBJDIR)
					@rm -rf $(CHECKER)
					@rm -rf $(PUSH_SWAP)
					@make --directory=./libft fclean
					@printf "\033[0;32mfclean: DONE\033[0m\n"

re:
					@rm -rf $(CHECKER_OBJS)
					@rm -rf $(PS_OBJS)
					@rm -rf $(OBJDIR)
					@rm -rf $(CHECKER)
					@rm -rf $(PUSH_SWAP)
					@make --directory=./libft fclean
					@make all


.PHONY:				all clean fclean re

.NOTPARALLEL:		all clean fclean re
