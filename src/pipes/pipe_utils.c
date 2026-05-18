/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:07:52 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/30 12:04:06 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void heredonc(t_shell *shell, int iter)
{
	int fd[2];
	char *read;
	char *token;

	pipe(fd);
	token = shell->tokens[shell->nex_exec+ iter + 1];
	read = readline(">");
	while (ft_strncmp(read, token, ft_strlen(token) + 1))
	{
		write(fd[1], read, ft_strlen(read));
		write(fd[1], "\n", 1);
		free(read);
		read = readline(">");
	}
	free(read);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
}

void open_redirect(t_shell *shell, int iter)
{
	int fd;
	char *token; 

	fd = -1;
	token = shell->tokens[shell->nex_exec + iter + 1];
	if (shell->list_tokens[shell->nex_exec + iter] == 4)
	{
		fd = open(token, O_INPUT);
		dup2(fd, 0);
	}
	if (shell->list_tokens[shell->nex_exec + iter] == 3)
	{
		fd = open(token, O_OUTPUT, 0644);
		dup2(fd, 1);
	}
	if (shell->list_tokens[shell->nex_exec + iter] == 5)
	{
		fd = open(token, O_APPEND_F, 0644);
		dup2(fd, 1);
	}
	if (shell->list_tokens[shell->nex_exec + iter] == 6)
		heredonc(shell, iter);
	if (fd != -1)
		close(fd);
}

int	next_exect(t_shell *shell)
{
	int n;

	n = shell->nex_exec;
	while(shell->tokens[n])
	{
		if (shell->list_tokens[n] == 2)
		{
			return (n + 1);	
		}
		n++;
	}
	return (0);
}

int	contun_child(int *list_tokens, int num_tokens)
{
	int n;
	int num_child;

	n = 0;
	num_child = 0;
	while (n < num_tokens)
	{
		if (list_tokens[n] == 2)
			num_child++;
		n++;
	}
	return (num_child + 1);
}

void wait_children(t_shell *shell, int num_child)
{
	int		status;
	
	signals_parent_exec();	
	while (num_child > 0)
	{
		waitpid(-1, &status, 0);
		num_child--;
	}
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->exit_status = 128 + WTERMSIG(status);
	check_child_signal(status);
}
