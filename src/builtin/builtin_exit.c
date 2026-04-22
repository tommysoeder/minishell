/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:03:16 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/22 18:07:32 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit(t_shell *shell)
{
	int n;

	n = 0;
	if (shell->tokens[1])
		n = ft_atoi(shell->tokens[1]);
	exit(n);
}