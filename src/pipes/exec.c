/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:00:00 by aialonso          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_posix(t_shell *shell)
{
	char	*exec;
	char	*result;

	result = NULL;
	if (!ft_strchr(shell->tokens[shell->nex_exec], '/'))
	{
		exec = ft_strjoin("/", shell->tokens[shell->nex_exec]);
		if (!exec)
			exit(1);
		result = find_path(shell->envp, exec);
	}
	else if (!access(shell->tokens[shell->nex_exec], X_OK))
		result = ft_strdup(shell->tokens[shell->nex_exec]);
	return (result);
}

char	*contruc_exect(t_shell *shell, char ***exec_token)
{
	char	*result;
	int		n;

	n = 0;
	result = is_posix(shell);
	if (!result)
		return (NULL);
	while (shell->tokens[shell->nex_exec + n]
		&& shell->list_tokens[shell->nex_exec + n] == 1)
		n++;
	*exec_token = calloc(n + 1, sizeof(char *));
	if (!*exec_token)
		return (free(result), NULL);
	n = 0;
	while (shell->tokens[shell->nex_exec + n]
		&& shell->list_tokens[shell->nex_exec + n] == 1)
	{
		(*exec_token)[n] = shell->tokens[shell->nex_exec + n];
		n++;
	}
	return (result);
}

void	exec_child(t_shell *shell, int prev_fd, int next_fd)
{
	char	*path_result;
	char	**exec_token;

	if (prev_fd != -1)
	{
		dup2(prev_fd, 0);
		close(prev_fd);
	}
	if (next_fd != -1)
	{
		dup2(next_fd, 1);
		close(next_fd);
	}
	apply_redirects(shell);
	path_result = contruc_exect(shell, &exec_token);
	if (!path_result)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(shell->tokens[shell->nex_exec], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	execve(path_result, exec_token, shell->envp);
	free(path_result);
	exit(1);
}
