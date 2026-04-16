/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:52:29 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/16 15:49:30 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include "signals.h"
# include "libft.h"

typedef struct s_shell
{
	char	*line;
	void	*resultado;
	char	**tokens;
	int		num_tokens;
	int		*list_tokens;
}	t_shell;

void	tokenize_input(char	*line, t_shell *shell);
void	cheker_end_line(char **line);
int		who_com(char *line);
int		cout_len_token(char *str);
char	*save_token(char	**line);
int		is_oper(char str);

#endif