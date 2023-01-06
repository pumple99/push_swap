# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 15:20:31 by seunghoy          #+#    #+#              #
#    Updated: 2022/12/21 17:23:42 by seunghoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Werror -Wall -Wextra
LIB = libft.a
LIB_DIR = ./libft

SRCS_C = error.c input.c operation.c stack.c

SRCS_B = main_bonus.c

OBJS_C = $(SRCS_C:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
DEPS = $(OBJS_C:.o=.d) $(OBJS_B:.o=.d) $(BONUS).d

all : $(LIB)
	rm -f $(NAME)
	cp $(LIB) $(NAME)
	make all_temp

all_temp : $(OBJS)
	ar -rcs $(NAME) $(OBJS) 
	rm -f bonus
	touch all

$(NAME) : all

bonus : $(LIB)
	make bonus_temp

bonus_temp : $(OBJS_B) $(OBJS_C)
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) -MMD -o $(BONUS) $^ $(LIB) -g

%.o : %.c
	$(CC) $(CFLAGS) -c -I. -MMD $< -g

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)

clean :
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS_C) $(OBJS_B) $(LIB) $(DEPS)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME) $(BONUS)

re :
	make fclean
	make all

ifeq "$(filter clean fclean re,$(MAKECMDGOALS))" ""
-include $(DEPS)
endif

.PHONY : clean fclean re
