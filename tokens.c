/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:03:05 by aialonso          #+#    #+#             */
/*   Updated: 2026/03/06 19:15:57 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_tokens(char	*line)
{
	int	flag;
	int	count_tokens;

	flag = 0;
	count_tokens = 0;
	while (!line)
	{
		if (flag == 0 && (*line != ' ' && *line != '\0'))
		{
			flag++;
			count_tokens++;
		}
		if (*line == ' ' || *line == '\0')
			flag--;
		line++;
	}
	return (count_tokens);
}

void	tokenize_input(char	*line)
{
	char	**tokes;

	tokes = malloc(sizeof(char *) * (count_tokens(line) + 1));
	return ;
}
