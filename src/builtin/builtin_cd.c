/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:23:39 by aialonso          #+#    #+#             */
/*   Updated: 2026/05/21 13:53:56 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(t_shell *shell)
{
	char	*pwd;
	char	*ruta;
	char	buf[PATH_MAX];
	int		n;

	n = 1;
	ruta = "";
	while (shell->list_tokens[n] && shell->list_tokens[n] == 1)
		n++;
	if (n > 2)
		return (-1);
	pwd = get_env_value(shell->envp, "PWD");
	if (!shell->tokens[1])
		ruta = get_env_value(shell->envp, "HOME");
	else if (ft_strncmp(shell->tokens[1], "-", 2) == 0)
		ruta = get_env_value(shell->envp, "OLDPWD");
	else if (shell->list_tokens[1] == 1)
		ruta = shell->tokens[1];
	if (!ruta || chdir(ruta))
		return (-1);
	set_env_value(&shell->envp, "OLDPWD", pwd);
	if (!getcwd(buf, PATH_MAX))
		return (-1);
	set_env_value(&shell->envp, "PWD", buf);
	return (0);
}
