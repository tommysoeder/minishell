/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:13:46 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/30 12:04:15 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void apply_redirects(t_shell *shell)
{
	int n;

	n = 0;
	while (shell->tokens[shell->nex_exec + n])
	{
		if (shell->list_tokens[shell->nex_exec + n] != 1)
			open_redirect(shell, n);
		n++;
	}
}

char *contruc_exect(t_shell *shell, char ***exec_token)
{
	char	*exec;
	char	*result;
	int		n;
	
	n = 0;
	exec = ft_strjoin("/", shell->tokens[shell->nex_exec]);
	if (!exec)
		exit(1);
	result = find_path(shell->envp, exec);
	if(!result)
		return (NULL);
	while(shell->tokens[shell->nex_exec + n]
		&& shell->list_tokens[shell->nex_exec + n] == 1)
		n++;
	*exec_token = calloc(n + 1, sizeof(char *));
	if (!*exec_token)
		return (free(result), NULL);
	n = 0;
	while(shell->tokens[shell->nex_exec + n]
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

void	init_pipes(t_shell *shell, int *prev_fd, int n)
{
	int		fd[2];
	
	if (n < shell->num_child - 1)
		pipe(fd);
	shell->pid[n] = fork();
	if (shell->pid[n] == 0)
	{
		signals_child_exec();
		if (n == 0 && shell->num_child == 1)
			exec_child(shell, -1, -1);
		else if (n == 0)
			exec_child(shell, -1, fd[1]);
		else if (n == shell->num_child - 1)
			exec_child(shell, *prev_fd, -1);
		else
			exec_child(shell, *prev_fd, fd[1]);
		exit(1);
	}
	if (*prev_fd != -1)
		close(*prev_fd);
	if (n < shell->num_child - 1)
	{	
		close(fd[1]);
		*prev_fd = fd[0];
	}
}

void	init_forks(t_shell *shell)
{
	int		n;
	int		prev_fd;
	
	n = 0;
	prev_fd = -1;
	shell->pid = calloc(shell->num_child, sizeof(pid_t));
	while (n < shell->num_child)
	{
		init_pipes(shell, &prev_fd, n);
		n++;
		shell->nex_exec = next_exect(shell);
	}
	if (prev_fd != -1)
		close(prev_fd);
	free(shell->pid);
	shell->pid = NULL;
	wait_children(shell, n);
}
