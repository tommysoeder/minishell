# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 13:18:47 by aialonso          #+#    #+#              #
#    Updated: 2026/05/18 23:46:27 by aialonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC_PUS = inc
SRC_PATH = src

SOURCES =	$(addprefix $(SRC_PATH)/,\
			ft_bzero.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_putstr_fd.c\
			ft_isspace.c\
			ft_calloc.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strlcpy.c\
			ft_strncpm.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isnumeric.c\
			ft_strlen.c)

FLAGS = -Wall -Wextra -Werror
CC = cc
FLA_I = -I $(INC_PUS)

OBJECTS= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):$(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	@$(CC) $(FLAGS) $(FLA_I) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

cleanb:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.DEFAULT_GOAL=all