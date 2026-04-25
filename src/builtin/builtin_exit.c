/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:03:16 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/25 14:20:07 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit(t_shell *shell)
{
	int n;

	n = 0;
	if ((shell->tokens[1] && ft_isnumeric(shell->tokens[1]))
		|| shell->num_tokens > 2)
	{
		shell->exit_status = 2;
		printf("%s: ", shell->tokens[0]);
		if(shell->num_tokens > 2)
			printf("too many arguments\n");
		else
			printf("%s: invalid integer\n", shell->tokens[1]);
		return ;
	}
	if (shell->tokens[1])
		n = ft_atoi(shell->tokens[1]);
	free_shell(shell);
	exit(n);
}
