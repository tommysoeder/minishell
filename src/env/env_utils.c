/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 23:36:22 by aialonso          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_key_len(char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (i);
}

int	find_env_index(char **envp, char *key)
{
	int	i;
	int	key_len;

	i = 0;
	if (!envp || !key)
		return (-1);
	key_len = ft_strlen(key);
	while (envp[i])
	{
		if (env_key_len(envp[i]) == key_len
			&& ft_strncmp(envp[i], key, key_len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_env_value(char **envp, char *key)
{
	int	index;
	int	key_len;

	if (envp == NULL)
		return (NULL);
	if (key == NULL)
		return (NULL);
	if (*key == '\0')
		return (NULL);
	index = find_env_index(envp, key);
	if (index == -1)
		return (NULL);
	key_len = ft_strlen(key);
	if (envp[index][key_len] != '=')
		return (NULL);
	return (envp[index] + key_len + 1);
}

int	is_valid_env_key(char *key)
{
	int	i;

	if (!key || !*key)
		return (0);
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	i = 1;
	while (key[i])
	{
		if (!ft_isalpha(key[i]) && !ft_isdigit(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	unset_env_value(char ***envp, char *key)
{
	int	index;

	if (!envp || !is_valid_env_key(key))
		return (1);
	index = find_env_index(*envp, key);
	if (index == -1)
		return (0);
	free((*envp)[index]);
	while ((*envp)[index])
	{
		(*envp)[index] = (*envp)[index + 1];
		index++;
	}
	return (0);
}
