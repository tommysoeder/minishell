/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:52:29 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/23 18:17:30 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "signals.h"
# include "libft.h"
# include "tokens.h"
# include "env.h"
# include "path.h"

# define PATH_MAX 4096

typedef struct s_shell
{
	char	*line;
	void	*resultado;
	char	**tokens;
	int		num_tokens;
	int		*list_tokens;
	int		exit_status;
	char	**envp;
}	t_shell;


void	cheker_end_line(char **line);
int		who_com(char *line);
int		tokenize_input(char	*line, t_shell *shell);
int		free_shell(t_shell *shell);
void	free_tokens(char ***tokens, int **list_tokens);
t_shell	*init_shell(char **envp, int argv, char **argc);
int		init_comand(t_shell	*shell);
void	init_exe(t_shell	*shell);
int		is_builtin(char *token);
void	exet_builtin(t_shell *shell);
void	builtin_cd(t_shell *shell);
void	builtin_echo(t_shell *shell);
void	builtin_env(t_shell *shell);
void	builtin_exit(t_shell *shell);
void	builtin_pwd(void);

#endif