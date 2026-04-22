/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:35:28 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/22 15:14:48 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	shell = init_shell(envp, argc, argv);
	if (!shell)
		return (1);
	while (1)
	{
		signals_interactive();
		if (init_comand(shell) == 1)
			break ;
		init_exe(shell);
		free_tokens(&shell->tokens, &shell->list_tokens);
		free(shell->line);
		shell->line = NULL;
	}
	return (free_shell(shell));
}
