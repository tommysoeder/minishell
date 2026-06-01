/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:17:37 by aialonso          #+#    #+#             */
/*   Updated: 2026/05/28 01:47:33 by aialonso         ###   ########.fr       */
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
	shell->envp = copy_envp(envp);
	if (!shell->envp)
		return (free(shell), NULL);
	shell->exit_status = 0;
	shell->nex_exec = 0;
	shell->num_child = 0;
	shell->pid = NULL;
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

void	init_exe(t_shell	*shell)
{
	int	save_stdin;
	int	save_stdout;

	if (!shell->line || !shell->tokens[0] || shell->list_tokens[0] != 1)
		return ;
	shell->num_child = contun_child(shell->list_tokens, shell->num_tokens);
	if (is_builtin(shell->tokens[0]) == 0)
		init_forks(shell);
	else
	{
		save_stdin = dup(0);
		save_stdout = dup(1);
		apply_redirects(shell);
		exet_builtin(shell);
		dup2(save_stdin, 0);
		dup2(save_stdout, 1);
		close(save_stdin);
		close(save_stdout);
	}
}
