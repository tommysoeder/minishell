# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 12:33:05 by aialonso          #+#    #+#              #
#    Updated: 2026/04/29 19:57:33 by aialonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRC_PATH = src
LIB = lib


SOURCES =   $(addprefix $(SRC_PATH)/,\
			signals/signals.c\
			cheker_line.c\
			main.c\
			pipes/pipe_utils.c\
			pipes/pipes.c\
			builtin/builtin_cd.c\
			builtin/builtin_echo.c\
			builtin/builtin_env.c\
			builtin/builtin_exit.c\
			builtin/builtin_export.c\
			builtin/builtin_pdw.c\
			builtin/builtin_unset.c\
			check_builtin.c\
			init.c\
			free.c\
			env/env_utils.c\
			find_path.c\
			tokens/tokens.c\
			tokens/fix_quotes_check.c\
			tokens/fix_quotes_copy.c\
			tokens/fix_quotes_utils.c\
			tokens/fix_quotes.c\
			tokens/token_utils.c\
			)

INC_PUS = inc
INC_LIB = $(LIB)/inc

FLA_I = -I $(INC_PUS)
FLA_I_LIB = -I $(INC_LIB)

COM_LIB = $(LIB)/libft.a

FLAGS = -Wall -Wextra -Werror -g3
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
