/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:01:53 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/18 15:20:45 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

/* Token sin impiar */

int		cout_len_token(char *str);
char	*save_token(char	**line);
int		is_oper(char str);

/* Token limpios */

int		clean_tokens(char **tokens, char **var);
int		is_special_char(char str);
int		is_var_char(char str);
int		len_sing(char *str, int *iter);
int		len_double_quote(char *str, char **var, int *iter);
int		len_env_var(char *str, char **var, int *iter);
int		skip_var_name(char *str, int *iter);
void	cop_sing(char **new_token, char *token, int *n);
void	copy_double_quote(char **new_token, char *token, int *z, char **var);
void	copy_env_var(char **new_token, char *token, int *z, char **var);

#endif