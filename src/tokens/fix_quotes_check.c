/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_quotes_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:24:46 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/25 10:45:21 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special_char(char str)
{
	if (str == 92)
		return (1);
	if (str == 34)
		return (1);
	if (str == '$')
		return (1);
	if (str == 39)
		return (1);
	return (0);
}

int	is_var_char(char str)
{
	if (ft_isalpha(str))
		return (1);
	else if (ft_isdigit(str))
		return (1);
	else if (str == '_')
		return (1);
	return (0);
}

void	is_status(char *str, int *count, t_shell *shell, int *iter)
{
	char	*number;

	if (str[*iter - 1] == '$' && str[*iter] == '?')
	{
		number = ft_itoa(shell->exit_status);
		*count = ft_strlen(number);
		free(number);
		(*iter)++;
	}
}

int	copy_status(char *str, char **new_token, t_shell *shell, int *iter)
{
	char	*number;
	int		n;

	if (str[*iter] == '$' && str[*iter + 1] == '?')
	{
		n = 0;
		number = ft_itoa(shell->exit_status);
		while (number[n])
		{
			**new_token = number[n];
			n++;
			(*new_token)++;
		}
		free(number);
		(*iter)++;
		return (1);
	}
	return (0);
}
