/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:59:48 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/08 17:57:33 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_token(char *str)
{
	int	count;
	int	iter;

	count = 0;
	iter = 0;
	while ((str[iter] != 34 && str[iter] != 39) || str[iter])
	{
		if (str[iter] == '$' && str[0] == 34)
		{
			//count = count + funcion();
			while (str[iter] != ' ' && str[iter] != '\0' && str[iter] != 34)
				iter++;
			continue ;
		}
		iter++;
	}
	if (str[iter] == '\0')
		return (-1);
	count = count + iter;
	return (count);
}

void	handle_double_quotes(char **str, char *new_token)
{
	int	count;

	count = 0;
	while ((*str)[count + 1] != 39)
	{
		if ((*str)[count] == '$')
		{
			//algo(); //añadir la variable del $ en new_token
		}
		new_token[count] = (*str)[count + 1];
		count++;
	}
}

void	fix_quotes_in_token(char **str)
{
	int		count;
	char	*new_token;

	count = count_token(*str);
	if (count <= 0)
		return ;
	new_token = malloc(sizeof(char) * count);
	if (!new_token)
		return ;
	new_token[count - 1] = '\0';
	count = 0;
	if (**str == 34)
	{
		handle_double_quotes(str, new_token);
	}
	else
	{
		while ((*str)[count + 1] != 39)
		{
			new_token[count] = (*str)[count + 1];
			count++;	
		}
	}
	free(*str);
	*str = new_token;
}
