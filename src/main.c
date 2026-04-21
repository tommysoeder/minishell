/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:35:28 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/20                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;
	int		n;

	(void)argc;
	(void)argv;
	n = 0;
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (1);
	ft_bzero(shell, sizeof(t_shell));
	shell->envp = envp;
	while (1)
	{
		signals_interactive();
		shell->line = readline("minishell$ ");
		if (!shell->line)
		{
			printf("exit\n");
			break ;
		}
		cheker_end_line(&shell->line);
		if (*shell->line)
			add_history(shell->line);
		tokenize_input(shell->line, shell);
		expand_tokens(shell);
		free(shell->line);
		n = shell->num_tokens;
		while (n > 0)
		{
			printf("Resultado numero %d: |%s| tipo de token %d \n",
				(shell->num_tokens - n),
				shell->tokens[shell->num_tokens - n],
				shell->list_tokens[shell->num_tokens - n]);
			free(shell->tokens[shell->num_tokens - n--]);
		}
		free(shell->list_tokens);
		free(shell->tokens);
	}
	free(shell);
	return (0);
}
