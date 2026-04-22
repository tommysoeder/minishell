/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:21:30 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/22 18:01:18 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void builtin_echo(t_shell *shell)
{
	int n;
	int flag;

	n = 1;
	flag = 0;
	if (ft_strncmp(shell->tokens[1], "-n", 2) == 0)
	{
		n++;
		flag = 1;
	}
	while (shell->list_tokens[n] == 1)
	{
		printf("%s ", shell->tokens[n]);
		n++;
	}
	if (flag == 0)
		printf("\n");
}
