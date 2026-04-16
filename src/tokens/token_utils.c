/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:38:26 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/16 15:49:16 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_oper(char str)
{
	if (str == 124)
		return (1);
	if (str == 60)
		return (1);
	if (str == 62)
		return (1);
	return (0);
}

char	*save_token(char	**line)
{
	int		count;
	int		iter;
	char	*token;

	while (ft_isspace(**line))
		(*line)++;
	count = cout_len_token(*line);
	token = malloc(sizeof(char) * (count + 1));
	token[count] = '\0';
	iter = 0;
	while (iter < count)
	{
		token[iter] = **line;
		iter++;
		(*line)++;
	}
	return (token);
}

int	cout_len_token(char *str)
{
	int	count;

	count = 0;
	if (is_oper(*str))
		return (is_oper(*str) + is_oper(str[1]));
	while (str[count])
	{
		if (ft_isspace(str[count]) || is_oper(str[count]))
			break ;
		count += who_com(str + count);
	}
	return (count);
}

int	who_com(char *line)
{
	int	flag;
	int	iter;

	iter = 0;
	if (line[iter] == 34 || line[iter] == 39)
	{
		flag = line[iter];
		iter++;
		while (line[iter] != flag && line[iter] != '\0')
		{
			if (line[iter] == 92 && line[iter + 1] == flag)
				iter++;
			iter++;
		}
	}
	return (iter + 1);
}
