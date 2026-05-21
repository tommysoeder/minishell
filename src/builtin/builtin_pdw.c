/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pdw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:08:57 by aialonso          #+#    #+#             */
/*   Updated: 2026/05/21 13:55:22 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(t_shell *shell)
{
	char	buf[PATH_MAX];

	if (!getcwd(buf, PATH_MAX))
	{
		shell->exit_status = 1;
		return ;
	}
	printf("%s\n", buf);
	shell->exit_status = 0;
}
