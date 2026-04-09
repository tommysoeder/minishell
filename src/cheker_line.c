/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:37:14 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/08 18:17:16 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_realloc(char *str1, char *str2)
{
	int 	len1;
	int 	len2;
	int 	iter;
	char	*line;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	line = calloc(len1 + len2, sizeof(char));
	iter = 0;
	while (iter < len1 + len2)
	{
		if (iter <= len1)
		{
			line[iter] = str1[iter];
			iter++;
			continue;
		}
		line[iter] = str2[iter + len1];
		iter++;
	}
	free(str1);
	free(str2);
	return (line);
}

void	cheker_end_line(char **line)
{
	int	i;
	int	flag;
	char *temp;

	i = 0;
	flag = 0;
	while ((*line)[i])
	{
		if (((*line)[i] == 34 || (*line)[i] == 39) && flag == 0)
		{
			flag = (*line)[i] - '0';
			i++;
			continue ;
		}
		if ((*line)[i] == 34 && flag == 34)
			flag = 0;
		else if ((*line)[i] == 39 && flag == 39)
			flag = 0;
		if (!(*line)[i + 1] && flag != 0)
		{
			temp = readline("");
			*line = ft_realloc(*line, temp);
		}
		i++;
	}
}
