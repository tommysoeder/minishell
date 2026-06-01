/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:13:46 by aialonso          #+#    #+#             */
/*   Updated: 2026/06/01 22:00:53 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	apply_redirects(t_shell *shell)
{
	int	n;

	n = 0;
	while (shell->tokens[shell->nex_exec + n]
		&& shell->list_tokens[shell->nex_exec + n] != 2)
	{
		if (shell->list_tokens[shell->nex_exec + n] != 1)
			open_redirect(shell, n);
		n++;
	}
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
		if (shell->nex_exec != 0)
			if (shell ->list_tokens[shell->nex_exec] != 1)
			{
				shell->nex_exec = 0;
				break;
			}
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
