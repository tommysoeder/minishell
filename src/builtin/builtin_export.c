/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by tomamart         #+#    #+#             */
/*   Updated: 2026/05/18 00:00:00 by tomamart        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_export_entry(char *entry)
{
	int	i;

	i = 0;
	printf("declare -x ");
	while (entry[i] && entry[i] != '=')
		printf("%c", entry[i++]);
	if (entry[i] == '=')
		printf("=\"%s\"", entry + i + 1);
	printf("\n");
}

static int	export_arg(t_shell *shell, char *arg)
{
	char	*equal;
	char	*key;
	int		status;

	status = 0;
	equal = ft_strchr(arg, '=');
	if (!equal)
		key = ft_strdup(arg);
	else
		key = ft_substr(arg, 0, equal - arg);
	if (!key)
		return (1);
	if (!get_env_value(shell->envp, key))
		status = set_env_value(&shell->envp, key, NULL);
	if (equal && status == 0)
		status = set_env_value(&shell->envp, key, equal + 1);
	if (status != 0)
		printf("minishell: export: `%s': not a valid identifier\n", arg);
	free(key);
	return (status);
}

void	builtin_export(t_shell *shell)
{
	int	i;

	i = 0;
	shell->exit_status = 0;
	if (shell->num_tokens == 1)
	{
		while (shell->envp && shell->envp[i])
			print_export_entry(shell->envp[i++]);
		return ;
	}
	i = 1;
	while (shell->tokens[i] && shell->list_tokens[i] == 1)
	{
		if (export_arg(shell, shell->tokens[i]) != 0)
			shell->exit_status = 1;
		i++;
	}
}
