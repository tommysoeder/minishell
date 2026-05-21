/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by tomamart         #+#    #+#             */
/*   Updated: 2026/05/18 00:00:00 by tomamart        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_unset(t_shell *shell)
{
	int	i;

	i = 1;
	shell->exit_status = 0;
	while (shell->tokens[i] && shell->list_tokens[i] == 1)
	{
		if (unset_env_value(&shell->envp, shell->tokens[i]) != 0)
			shell->exit_status = 1;
		i++;
	}
}
