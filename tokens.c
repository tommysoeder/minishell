/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:03:05 by aialonso          #+#    #+#             */
/*   Updated: 2026/03/16 17:49:19 by aialonso         ###   ########.fr       */
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

char	*save_token(char	**line)
{
	int		count;
	char	*token;

	count = 0;
	while ((*line)[count])
	{
		if ((*line)[count] == ' ')
			break ;
		count++;
	}
	token = malloc(sizeof(char) * (count + 1));
	token[count] = '\0';
	count = 0;
	while (**line)
	{
		if (**line == ' ')
		{
			*line = *line + 1;
			break ;
		}
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
	list_tokens = malloc(sizeof(int) * count_tokens(line));
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
