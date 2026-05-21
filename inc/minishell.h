/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:52:29 by aialonso          #+#    #+#             */
/*   Updated: 2026/05/21 14:10:19 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PATH_MAX 4096

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "signals.h"
# include "libft.h"
# include "env.h"
# include "path.h"
# include "tokens.h"

typedef struct s_shell
{
	char	*line;
	char	**tokens;
	int		num_tokens;
	int		*list_tokens;
	int		exit_status;
	int		nex_exec;
	int		num_child;
	char	**envp;
	pid_t	*pid;
}	t_shell;

void	cheker_end_line(char **line);
int		who_com(char *line);
int		tokenize_input(char *line, t_shell *shell);
int		free_shell(t_shell *shell);
void	free_tokens(char ***tokens, int **list_tokens);
t_shell	*init_shell(char **envp, int argv, char **argc);
int		init_comand(t_shell *shell);
void	init_exe(t_shell *shell);
int		is_builtin(char *token);
void	exet_builtin(t_shell *shell);
int		builtin_cd(t_shell *shell);
void	builtin_echo(t_shell *shell);
void	builtin_env(t_shell *shell);
void	builtin_exit(t_shell *shell);
void	builtin_export(t_shell *shell);
void	builtin_pwd(t_shell *shell);
void	builtin_unset(t_shell *shell);
void	exec_child(t_shell *shell, int prev_fd, int next_fd);
char	*is_posix(t_shell *shell);
int		contun_child(int *list_tokens, int num_tokens);
int		next_exect(t_shell *shell);
void	init_forks(t_shell *shell);
void	wait_children(t_shell *shell, int num_child);
void	open_redirect(t_shell *shell, int iter);
void	apply_redirects(t_shell *shell);

#endif