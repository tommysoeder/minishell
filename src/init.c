/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:17:37 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/25 14:31:25 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*init_shell(char **envp, int argc, char **argv)
{
	t_shell	*shell;
	(void)argv;
	(void)argc;

	shell = calloc(1, sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->envp = envp;
	shell->exit_status = 0;
	return (shell);
}

int	init_comand(t_shell	*shell)
{
	shell->line = readline("minishell$ ");
	if (!shell->line)
		return (1);
	if (shell->line[0] == '\0')
	{
		free(shell->line);
		shell->line = NULL;
		return (0);
	}
	cheker_end_line(&shell->line);
	if (!shell->line)
		return (1);
	add_history(shell->line);
	if (tokenize_input(shell->line, shell) == 1)
		return (1);
	if (clean_tokens(shell->tokens, shell) == 1)
		return (1);
	return (0);
}

void	init_fork(char *path_result, t_shell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		signals_child_exec();
		execve(path_result, shell->tokens, shell->envp);
		exit(1);
	}
	else
	{
		signals_parent_exec();	
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			shell->exit_status = 128 + WTERMSIG(status);
		check_child_signal(status);
	}
	free(path_result);
}

void	init_exe(t_shell	*shell)
{

	char	*exet;
	char	*path_result;

	if (!shell->line)
		return ;
	if(is_builtin(shell->tokens[0]) == 0)
	{
		exet = ft_strjoin("/", shell->tokens[0]);
		if (!exet)
			return ;
		path_result = find_path(shell->envp, exet);
		if (path_result)
			init_fork(path_result, shell);
		else
		{	
			printf("minishell: %s: command not found\n", shell->tokens[0]);
			shell->exit_status = 127;
		}
		free(exet);
	}
	else
		exet_builtin(shell);
}
