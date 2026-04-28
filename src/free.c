/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:28:02 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/25 19:15:25 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_shell(t_shell *shell)
{
	if (!shell)
		return (0);
	rl_clear_history();
	free_tokens(&shell->tokens, &shell->list_tokens);
	free(shell->line);
	shell->line = NULL;
	free(shell);
	shell = NULL;
	return (0);
}

void	free_tokens(char ***tokens, int **list_tokens)
{
	int n;

	n = 0;
	if (!tokens || !*tokens)
		return ;
	while ((*tokens)[n])
	{
		free((*tokens)[n]);
		(*tokens)[n] = NULL;
		n++;
	}
	if (list_tokens && *list_tokens)
	{	
		free(*list_tokens);
		*list_tokens = NULL;
	}
	free(*tokens);
	*tokens = NULL;
}
