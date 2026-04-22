/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:37:46 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/22 16:24:10 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path(char **envp, char *token)
{
	char		*path;
	char		**paths;
	static char	*resul;
	int			n;

	path = get_env_value(envp, "PATH");
	paths = ft_split(path, ':');
	n = -1;
	resul = NULL;
	while (paths && paths[++n])
	{
		resul = ft_strjoin(paths[n], token);
		if (resul && access(resul, X_OK))
		{
			free(resul);
			resul = NULL;
		}
		else
			break;
	}
	n = 0;
	while (paths && paths[n])
		free(paths[n++]);
	free(paths);
	return (resul);
}
