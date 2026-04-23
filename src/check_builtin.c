/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:52:33 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/23 18:21:46 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *token)
{
	if (ft_strncmp(token, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(token, "cd", 3) == 0)
		return (2);
	if (ft_strncmp(token, "echo", 5) == 0)
		return (3);
	if (ft_strncmp(token, "export", 7) == 0)
		return (4);
	if (ft_strncmp(token, "unset", 6) == 0)
		return (5);
	if (ft_strncmp(token, "env", 4) == 0)
		return (6);
	if (ft_strncmp(token, "exit", 5) == 0)
		return (7);
	return (0);
}

void	exet_builtin(t_shell *shell)
{
	if (is_builtin(shell->tokens[0]) == 1)
		builtin_pwd();
/* 	else if (is_builtin(shell->tokens[0]) == 2)
		builtin_cd(shell); */
	else if (is_builtin(shell->tokens[0]) == 3)
		builtin_echo(shell);
/* 	else if (is_builtin(shell->tokens[0]) == 4)
		builtin_export();
	else if (is_builtin(shell->tokens[0]) == 5)
		builtin_unset(); */
	else if (is_builtin(shell->tokens[0]) == 6)
		builtin_env(shell);
	else if (is_builtin(shell->tokens[0]) == 7)
		builtin_exit(shell);
}
