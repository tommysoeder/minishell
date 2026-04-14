/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:03:05 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/13 14:10:44 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tip_token(char *str)
{
	if (*str == 124)
		return (2);
	else if (*str == 60 && *(str + 1) == 60)
		return (6);
	else if (*str == 62 && *(str + 1) == 62)
		return (5);
	else if (*str == 60)
		return (4);
	else if (*str == 62)
		return (3);
	else
		return (1);
}

int cout_len_token(char *str)
{
	int count;
	int flag;

	count = 0;
	flag = 0;
	while (str[count])
	{
		if (flag != 0 && (str[count] == 34 || str[count] == 39) && str[count - 1] != 92)
			return (count - 1);
		if ((str[count] == 34 || str[count] == 39) && str[count - 1] != 92)
			flag = str[count];
		if (flag == 0 && str[count] == ' ')
			return (count);
		count++;
	}
	return (count);
}
char	*save_token(char	**line)
{
	int		count;
	int		flag;
	char	*token;
	
	while (ft_isspace(**line))
		(*line)++;
	count = cout_len_token(*line);
	token = malloc(sizeof(char) * (count + 1));
	token[count] = '\0';
	count = 0;
	flag = 0;
	while (**line)
	{
		if (**line == 92 && ((*line)[1] == 34 || (*line)[1] == 39))
		{
			(*line)++;
			token[count] = **line;
			count++;
			(*line)++;
			continue ;
		}
		if (flag != 0 && (**line == 34 || **line == 39))
			return (token);
		if (**line == 34 || **line == 39)
		{
			flag = **line;
			(*line)++;
		}
		if (flag == 0 && ft_isspace(**line))
			break ;
		token[count] = **line;
		count++;
		(*line)++;
	}
	return (token);
}

static int	count_tokens(char	*line)
{
	int	flag;
	int	count_tokens;

	flag = 0;
	count_tokens = 0;
	while (*line)
	{
		if (*line == 92 && (*(line + 1) == 34 || *(line + 1) == 39))
			line = line + 2;
		if (flag == 0 && (*line == 34 || *line == 39))
		{
			flag = *line;
			count_tokens++;
		}
		else if (flag == *line)
			flag -= *line - 1;
		if (flag == 0 && (*line != ' ' && *line != '\0'))
		{
			flag++;
			count_tokens++;
		}
		if (flag == 1 && (*line == ' ' || *line == '\0'))
			flag--;
		line++;
	}
	return (count_tokens);
}

void	tokenize_input(char	*line, t_shell *shell)
{
	char	**tokes;
	int		*list_tokens;
	int		iter;

	iter = 0;
	shell->num_tokens = count_tokens(line);
	tokes = malloc(sizeof(char *) * (shell->num_tokens + 1));
	if (!tokes)
		return ;
	tokes[shell->num_tokens] = NULL;
	list_tokens = malloc(sizeof(int) * shell->num_tokens);
	if (!list_tokens)
		return ;
	while (*line)
	{
		tokes[iter] = save_token(&line);
		list_tokens[iter] = tip_token(tokes[iter]);
		iter++;
	}
	shell->tokens = tokes;
	shell->list_tokens = list_tokens;
	return ;
}
