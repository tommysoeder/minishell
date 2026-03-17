/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:35:28 by aialonso          #+#    #+#             */
/*   Updated: 2026/03/17 14:33:32 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;
	t_shell	*shell;
	int		n;

	n = 0;
	shell = malloc(sizeof(t_shell));
	while (1)
	{
		signals_interactive(); // manejo de señales en modo interactivo
		line = readline("minishell$ ");
		if (!line)
		{
			break ;
			printf("exit\n");
		}
		if (*line)
			add_history(line);
		tokenize_input(line, shell);
		free(line);
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
