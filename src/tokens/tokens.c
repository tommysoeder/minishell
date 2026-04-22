/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:03:05 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/22 15:10:33 by aialonso         ###   ########.fr       */
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

static int	count_tokens(char *line)
{
	int	count_tokens;
	int	flag;

	count_tokens = 0;
	flag = 0;
	while (*line)
	{
		if (ft_isspace(*line))
			flag = 0;
		else if (is_oper(*line))
		{
			if (is_oper(*(line + 1)))
				line++;
			count_tokens++;
			flag = 0;
		}
		else if (flag == 0)
		{
			count_tokens++;
			flag = 1;
		}
		line += who_com(line);
	}
	return (count_tokens);
}

int	tokenize_input(char	*line, t_shell *shell)
{
	char	**tokes;
	int		*list_tokens;
	int		iter;

	iter = 0;
	shell->num_tokens = count_tokens(line);
	tokes = malloc(sizeof(char *) * (shell->num_tokens + 1));
	if (!tokes)
		return (1);
	tokes[shell->num_tokens] = NULL;
	list_tokens = malloc(sizeof(int) * shell->num_tokens);
	if (!list_tokens)
		return (free (tokes), 1);
	while (*line)
	{
		tokes[iter] = save_token(&line);
		if (!tokes[iter])
			return (free_tokens(&tokes, &list_tokens), 1);
		list_tokens[iter] = tip_token(tokes[iter]);
		iter++;
	}
	shell->tokens = tokes;
	shell->list_tokens = list_tokens;
	return (0);
}
