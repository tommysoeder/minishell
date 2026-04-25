/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:01:53 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/25 10:13:44 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

/* Token sin impiar */

int		cout_len_token(char *str);
char	*save_token(char	**line);
int		is_oper(char str);

/* Token limpios */

int		clean_tokens(char **tokens, t_shell *shell);
int		is_special_char(char str);
int		is_var_char(char str);
int		len_sing(char *str, int *iter);
int		len_double_quote(char *str, int *iter, t_shell *shell);
int		len_env_var(char *str, int *iter, t_shell *shell);
int		skip_var_name(char *str, int *iter);
void	cop_sing(char **new_token, char *token, int *n);
void	copy_double_quote(char **new_token, char *token, int *z, t_shell *shell);
void	copy_env_var(char **new_token, char *token, int *z, t_shell *shell);
void	is_status(char *str, int *count, t_shell *shell, int *iter);
int		copy_status(char *str, char **new_token, t_shell *shell, int *iter);

#endif