/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:37:14 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/22 15:23:18 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_realloc(char *str1, char *str2, int len1, int len2)
{
	int		iter;
	char	*line;

	line = ft_calloc(len1 + len2 + 2, sizeof(char));
	if (!line)
		return (free(str1), free(str2), NULL);
	iter = 0;
	while (iter < len1 + len2 + 1)
	{
		if (iter < len1)
			line[iter] = str1[iter];
		else if (iter == len1)
			line[iter] = '\n';
		else
			line[iter] = str2[iter - (len1 + 1)];
		iter++;
	}
	line[iter] = '\0';
	return (free(str1), free(str2), line);
}

void	cheker_end_line(char **line)
{
	int		i;
	int		flag;
	char	*temp;

	i = 0;
	flag = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == 92 && ((*line)[i + 1] == 34 || (*line)[i + 1] == 39))
			i = i + 2;
		if (((*line)[i] == 34 || (*line)[i] == 39) && flag == 0)
			flag = (*line)[i];
		else if ((*line)[i] == flag)
			flag = 0;
		if (!(*line)[i + 1] && flag != 0)
		{
			temp = readline(">");
			if (!temp)
				return (free(*line), (void)(*line = NULL));
			*line = ft_realloc(*line, temp, ft_strlen(*line), ft_strlen(temp));
			if (!*line)
				return ;
		}
		i++;
	}
}
