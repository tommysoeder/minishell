/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:35:28 by aialonso          #+#    #+#             */
/*   Updated: 2026/03/16 17:58:23 by aialonso         ###   ########.fr       */
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
		line = readline("minishell$ ");
		if (!line)
			break ;
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
