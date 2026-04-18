/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_quotes_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:25:41 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/18 11:17:56 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_var_name(char *str, int *iter)
{
	int	i;

	i = 0;
	while (is_var_char(str[*iter + i + 1]))
		i++;
	return (i + 1);
}

int	len_env_var(char *str, char **var, int *iter)
{
	int	n;
	int	i;
	int	count;

	n = 0;
	count = 0;
	while (var[n] != NULL)
	{
		i = 0;
		while (var[n][i] != '=')
		{
			if (var[n][i] != str[*iter + i + 1])
				break ;
			i++;
		}
		if (var[n][i] == '=' && !is_var_char(str[*iter + i +1]))
		{
			while (var[n][i + 1 + count])
				count++;
			break ;
		}
		n++;
	}
	*iter += skip_var_name(str, iter);
	return (count);
}

int	len_double_quote(char *str, char **var, int *iter)
{
	int	count;

	count = 0;
	(*iter)++;
	while (str[*iter] != 34)
	{
		if (str[*iter] == '$')
		{
			count += len_env_var(str, var, iter);
			continue ;
		}
		if (str[*iter] == 92 && is_special_char(str[*iter + 1]))
			(*iter)++;
		(*iter)++;
		count++;
	}
	(*iter)++;
	return (count);
}

int	len_sing(char *str, int *iter)
{
	int	count;

	count = 1;
	if (str[*iter] == 39)
	{
		(*iter)++;
		while (str[*iter] != 39)
		{
			count++;
			(*iter)++;
		}
		count--;
	}
	(*iter)++;
	return (count);
}
