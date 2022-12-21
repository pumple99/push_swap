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
CC = cc
CFLAGS = -Werror -Wall -Wextra
LIB = libft.a
LIB_DIR = ./libft

SRCS = 

SRCS_B =

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
DEPS = $(OBJS:.o=.d) $(OBJS_B:.o=.d)

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
	rm -f $(NAME)
	cp $(LIB) $(NAME)
	make bonus_temp

bonus_temp : $(OBJS_B)
	ar -rcs $(NAME) $(OBJS_B)
	rm -f all
	touch bonus

%.o : %.c
	$(CC) $(CFLAGS) -c -I. -MMD $<

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)

clean :
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS) $(OBJS_B) all bonus $(LIB) $(DEPS)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re :
	make fclean
	make all

ifeq "$(filter clean fclean re,$(MAKECMDGOALS))" ""
-include $(DEPS)
endif

.PHONY : clean fclean re
