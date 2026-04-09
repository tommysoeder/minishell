/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:35:28 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/08 18:21:11 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_shell	*shell;
	int		n;

	n = 0;
	shell = malloc(sizeof(t_shell));
	while (1)
	{
		signals_interactive(); // manejo de señales en modo interactivo
		shell->line = readline("minishell$ ");
		if (!shell->line)
		{
			break ;
			printf("exit\n");
		}
		cheker_end_line(&shell->line);
		add_history(shell->line);
		tokenize_input(shell->line, shell);
		free(shell->line);
		n = shell->num_tokens;
		while (n > 0)
		{
			printf("Resultado numero %d: |%s| tipo de token %d \n", (shell->num_tokens - n), shell->tokens[shell->num_tokens - n], shell->list_tokens[shell->num_tokens - n]);
			free(shell->tokens[shell->num_tokens - n--]);
		}
		free(shell->list_tokens);
		free(shell->tokens);
	}
	free(shell);
}
