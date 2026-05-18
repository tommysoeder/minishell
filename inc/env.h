/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:07:40 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/19 18:36:13 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

char	**copy_envp(char **envp);
void	free_envp(char **envp);
char	*get_env_value(char **envp, char *key);
int		set_env_value(char ***envp, char *key, char *value);
int		unset_env_value(char ***envp, char *key);
int		is_valid_env_key(char *key);

#endif
