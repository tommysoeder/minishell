/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:37:46 by aialonso          #+#    #+#             */
/*   Updated: 2026/05/30 13:44:38 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path(char **envp, char *token)
{
	char		*path;
	char		**paths;
	char		*resul;
	int			n;

	path = get_env_value(envp, "PATH");
	if (!path)
		return (NULL);
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
			break ;
	}
	n = 0;
	while (paths && paths[n])
		free(paths[n++]);
	free (paths);
	return (resul);
}
