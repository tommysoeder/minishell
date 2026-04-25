/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_quotes_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:25:37 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/25 10:50:14 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_env_var(char **n_token, char *token, int *z, t_shell *shell)
{
	int	n;
	int	i;

	n = 0;
	while (shell->envp[n] != NULL && copy_status(token, n_token, shell, z) == 0)
	{
		i = 0;
		while (shell->envp[n][i] != '=')
		{
			if (shell->envp[n][i] != token[*z + i + 1])
				break ;
			i++;
		}
		if (shell->envp[n][i] == '=' && !is_var_char(token[*z + i +1]))
		{
			while (shell->envp[n][++i])
			{
				(**n_token) = shell->envp[n][i];
				(*n_token)++;
			}
			break ;
		}
		n++;
	}
	*z += skip_var_name(token, z);
}

void	copy_double_quote(char **new_token, char *token, int *z, t_shell *shell)
{
	(*z)++;
	while (token[*z] != 34)
	{
		if (token[*z] == '$')
			copy_env_var(new_token, token, z, shell);
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
