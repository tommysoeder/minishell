/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_quotes_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:25:37 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/18 11:16:35 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_env_var(char **new_token, char *token, int *z, char **var)
{
	int	n;
	int	i;

	n = 0;
	while (var[n] != NULL)
	{
		i = 0;
		while (var[n][i] != '=')
		{
			if (var[n][i] != token[*z + i + 1])
				break ;
			i++;
		}
		if (var[n][i] == '=' && !is_var_char(token[*z + i +1]))
		{
			while (var[n][++i])
			{
				(**new_token) = var[n][i];
				(*new_token)++;
			}
			break ;
		}
		n++;
	}
	*z += skip_var_name(token, z);
}

void	copy_double_quote(char **new_token, char *token, int *z, char **var)
{
	(*z)++;
	while (token[*z] != 34)
	{
		if (token[*z] == '$')
			copy_env_var(new_token, token, z, var);
		else if (token[*z] == 92 && is_special_char(token[*z + 1]))
		{
			(*z)++;
			(**new_token) = token[*z];
			(*new_token)++;
			(*z)++;
		}
		else
		{
			(**new_token) = token[*z];
			(*new_token)++;
			(*z)++;
		}
	}
	(*z)++;
}

void	cop_sing(char **new_token, char *token, int *n)
{
	if (token[*n] == 39)
	{
		(*n)++;
		while (token[*n] != 39)
		{
			(**new_token) = token[*n];
			(*n)++;
			(*new_token)++;
		}
		(*n)++;
	}
	else
	{
		(**new_token) = token[*n];
		(*new_token)++;
		(*n)++;
	}
}
