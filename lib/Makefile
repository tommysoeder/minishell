# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 13:18:47 by aialonso          #+#    #+#              #
#    Updated: 2026/04/22 18:08:31 by aialonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC_PUS = inc
SRC_PATH = src

SOURCES =  	$(addprefix $(SRC_PATH)/,\
			ft_bzero.c\
			ft_atoi.c\
			ft_isspace.c\
			ft_calloc.c\
			ft_split.c\
			ft_strchr.c\
			ft_strlcpy.c\
			ft_strncpm.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_strlen.c)

FLAGS = -Wall -Wextra -Werror


FLA_I = -I $(INC_PUS)

CC = cc

OBJECTS= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):$(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	
%.o: %.c
	@$(CC) $(FLAGS) $(FLA_I) -c $< -o $@

clean:
	@rm -f $(OBJECTS) $(OBJECTSB)
	
cleanb:
	@rm -f $(OBJECTS) $(OBJECTSB)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all cleanb

comp: re
	$(CC) main.c $(NAME) -o librari
	./librari