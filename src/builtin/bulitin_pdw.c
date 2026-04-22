/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulitin_pdw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:08:57 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/22 17:17:51 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void builtin_pwd(void)
{
	char buf[PATH_MAX];
	
	getcwd(buf, PATH_MAX);
	printf("%s\n", buf);
}