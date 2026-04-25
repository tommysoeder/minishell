/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:58:59 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/25 11:05:33 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_env(t_shell *shell)
{
	int n;
	
	n = 0;
	while (shell->envp[n])
	{
		printf("%s\n", shell->envp[n]);
		n++;
	}
	shell->exit_status = 0;
}
