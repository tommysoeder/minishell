/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:59:48 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/21 17:57:27 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_real_token(char *str, char **var)
{
	int	len_token;
	int	iter;

	len_token = 0;
	iter = 0;
	while (str[iter])
	{
		if (str[iter] == 92 && is_special_char(str[iter + 1]))
		{
			len_token++;
			iter += 2;
			continue ;
		}
		if (str[iter] == 34)
			len_token += len_double_quote(str, var, &iter);
		else if (str[iter] == '$')
			len_token += len_env_var(str, var, &iter);
		else
			len_token += len_sing(str, &iter);
	}
	return (len_token);
}

static char	*copy_real_token(char *new_token, char *token, char **var)
{
	char	*copy_new_token;
	int		n;

	n = 0;
	copy_new_token = new_token;
	while (token[n])
	{
		if (token[n] == 92 && is_special_char(token[n + 1]))
		{
			n++;
			*new_token = token[n];
			new_token++;
			n++;
			continue ;
		}
		if (token[n] == 34)
			copy_double_quote(&new_token, token, &n, var);
		else if (token[n] == '$')
			copy_env_var(&new_token, token, &n, var);
		else
			cop_sing(&new_token, token, &n);
	}
	free(token);
	return (copy_new_token);
}

static int	clean_token(char **token, char **var)
{
	int		len_new;
	char	*new_token;

	len_new = count_real_token(*token, var);
	new_token = ft_calloc(len_new + 1, sizeof(char));
	if (!new_token)
		return (1);
	new_token[len_new] = '\0';
	*token = copy_real_token(new_token, *token, var);
	return (0);
}

int	clean_tokens(char **tokens, char **var)
{
	int	iter;

	iter = 0;
	while (tokens[iter])
	{
		if (clean_token(&tokens[iter], var) == 1)
			return (1);
		iter++;
	}
	return (0);
}
