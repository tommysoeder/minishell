/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:04:46 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/08 15:06:06 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>

char	*get_env_value(char **envp, char *key)
{
	int		i;
	size_t	key_len;

	if (envp == NULL)
		return (NULL);
	if (key == NULL)
		return (NULL);
	if (*key == '\0')
		return (NULL);
	key_len = ft_strlen(key);
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], key, key_len) == 0
			&& (envp[i][key_len] == '='))
			return (envp[i] + key_len + 1);
		i++;
	}
	return (NULL);
}

int is_var_char(char c)
{
    if ((c >= 'a' && c <= 'z') 
        || (c >= 'A' && c <= 'Z') 
        || (c >= '0' && c <= '9') 
        || c == '_')
        return (1);
    return (0);
}

char	*get_var_name(char *str, int i)
{
	char    *var_name;
	int     len;
    int     j;
    int     k;

    if (str == NULL || str[i] != '$' || !str[i + 1])
        return (NULL);
    j = i + 1;
    len = 0;
    while (is_var_char(str[j]))
    {
        len++;
        j++;
    }
    if (len == 0)
    {
        return (NULL);
    }
    var_name = (char *)malloc(sizeof(char) * (len + 1));
	if (!var_name)
		return (NULL);
    j = i + 1;
    k = 0;
    while (k < len)
    {
        var_name[k] = str[j];
        j++;
        k++;
    }
    var_name[k] = '\0';
    return (var_name);
}

static int	expanded_len(char *str, char **envp)
{
	int		i;
	int		len;
	int		var_len;
	char	*var_name;
	char	*value;

	if (!str)
		return (0);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			var_name = get_var_name(str, i);
			if (!var_name)
			{
				len++;
				i++;
			}
			else
			{
				value = get_env_value(envp, var_name);
				if (value)
					len += ft_strlen(value);
				var_len = ft_strlen(var_name);
				free(var_name);
				i += var_len + 1;
			}
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static int	copy_str_to_result(char *dst, char *src, int j)
{
	int	k;

	k = 0;
	while (src[k])
	{
		dst[j] = src[k];
		j++;
		k++;
	}
	return (j);
}

char	*expand_variables(char *str, char **envp)
{
	char	*result;
	char	*var_name;
	char	*value;
	int		i;
	int		j;
	int		var_len;

	if (!str)
		return (NULL);
	result = malloc(sizeof(char) * (expanded_len(str, envp) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			var_name = get_var_name(str, i);
			if (!var_name)
			{
				result[j] = str[i];
				j++;
				i++;
			}
			else
			{
				value = get_env_value(envp, var_name);
				if (value)
					j = copy_str_to_result(result, value, j);
				var_len = ft_strlen(var_name);
				free(var_name);
				i += var_len + 1;
			}
		}
		else
		{
			result[j] = str[i];
			j++;
			i++;
		}
	}
	result[j] = '\0';
	return (result);
}

void	expand_tokens(t_shell *shell)
{
	char	*expanded;
	int		i;

	if (!shell || !shell->tokens || !shell->envp)
		return ;
	i = 0;
	while (i < shell->num_tokens)
	{
		expanded = expand_variables(shell->tokens[i], shell->envp);
		if (expanded)
		{
			free(shell->tokens[i]);
			shell->tokens[i] = expanded;
		}
		i++;
	}
}