/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:52:29 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/20 19:38:36 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include "signals.h"

typedef struct s_shell
{
	char	*line;
	void	*resultado;
	char	**tokens;
	int		num_tokens;
	int		*list_tokens;
	char	**envp;
}	t_shell;

void	tokenize_input(char	*line, t_shell *shell);
void	cheker_end_line(char **line);
void	expand_tokens(t_shell *shell);
char	*expand_variables(char *str, char **envp);

#endif