/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:17:37 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/22 16:23:29 by aialonso         ###   ########.fr       */
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
	cheker_end_line(&shell->line);
	if (!shell->line)
		return (1);
	add_history(shell->line);
	if (tokenize_input(shell->line, shell) == 1)
		return (1);
	if (clean_tokens(shell->tokens, shell->envp) == 1)
		return (1);
	return (0);
}

void	init_exe(t_shell	*shell)
{
	int		status;
	pid_t	pid;
	char	*exet;
	char	*path_result;
	
	exet = ft_strjoin("/", shell->tokens[0]);
	if (!exet)
		return ;
	path_result = find_path(shell->envp, exet);
	if (path_result)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(path_result, shell->tokens, shell->envp);
			exit(1);
		}
		else
			waitpid(pid, &status, 0);
		free(path_result);
	}
	free(exet);
}
