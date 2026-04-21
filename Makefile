# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 12:33:05 by aialonso          #+#    #+#              #
#    Updated: 2026/04/20 19:39:12 by tomamart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRC_PATH = src
LIB = lib


SOURCES =   $(addprefix $(SRC_PATH)/,\
			signals/signals.c\
			env/env_utils.c\
			cheker_line.c\
			fix_quotes.c\
			main.c\
			tokens.c)

INC_PUS = inc
INC_LIB = $(LIB)/inc

FLA_I = -I $(INC_PUS)
FLA_I_LIB = -I $(INC_LIB)

COM_LIB = $(LIB)/libft.a

FLAGS = -Wall -Wextra -Werror -g
DFLAGS =  -L $(LIB) -lft -lreadline

CC = cc

OBJECTS= $(SOURCES:.c=.o)

$(COM_LIB):
	@make -C $(LIB)

all: $(NAME)

$(NAME): $(OBJECTS) $(COM_LIB)
	$(CC) $(FLAGS) $(FLA_I) $(FLA_I_LIB) $(OBJECTS) $(DFLAGS) -o $(NAME)
	
%.o: %.c
	@$(CC) $(FLAGS) $(FLA_I) $(FLA_I_LIB) -c $< -o $@

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJECTS)

rclean:
	@make cleanb -C $(LIB)
	@rm -f $(OBJECTS)
	
fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all rclean

.PHONY: all clean rclean fclean re

.DEFAULT_GOAL=all