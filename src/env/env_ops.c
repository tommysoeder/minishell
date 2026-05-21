/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by aialonso          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_count(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

char	**copy_envp(char **envp)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (env_count(envp) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
		{
			copy[i] = NULL;
			return (free_envp(copy), NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_envp(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return ;
	while (envp[i])
		free(envp[i++]);
	free(envp);
}

static int	append_env_value(char ***envp, char *entry)
{
	char	**new_envp;
	int		i;

	new_envp = malloc(sizeof(char *) * (env_count(*envp) + 2));
	if (!new_envp)
		return (free(entry), 1);
	i = 0;
	while (*envp && (*envp)[i])
	{
		new_envp[i] = (*envp)[i];
		i++;
	}
	new_envp[i] = entry;
	new_envp[i + 1] = NULL;
	free(*envp);
	*envp = new_envp;
	return (0);
}

int	set_env_value(char ***envp, char *key, char *value)
{
	char	*entry;
	char	*tmp;
	int		index;

	if (!envp || !is_valid_env_key(key))
		return (1);
	entry = ft_strdup(key);
	if (!entry)
		return (1);
	if (value)
	{
		tmp = ft_strjoin(entry, "=");
		free(entry);
		if (!tmp)
			return (1);
		entry = ft_strjoin(tmp, value);
		free(tmp);
	}
	if (!entry)
		return (1);
	index = find_env_index(*envp, key);
	if (index >= 0)
		return (free((*envp)[index]), (*envp)[index] = entry, 0);
	return (append_env_value(envp, entry));
}
