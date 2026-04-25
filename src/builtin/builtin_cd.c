/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:23:39 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/25 08:18:33 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	builtin_cd(t_shell *shell)
{
	char *pwd;
	char *home;

	pwd = get_env_value(shell->envp, "PWD");
	home = get_env_value(shell->envp, "HOME");
	if (!shell->tokens[1])
		chdir(home);
	
}
 */