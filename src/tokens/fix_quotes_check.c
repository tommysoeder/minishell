/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_quotes_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:24:46 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/18 11:15:08 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special_char(char str)
{
	if (str == 92)
		return (1);
	if (str == 34)
		return (1);
	if (str == '$')
		return (1);
	if (str == 39)
		return (1);
	return (0);
}

int	is_var_char(char str)
{
	if (ft_isalpha(str))
		return (1);
	else if (ft_isdigit(str))
		return (1);
	else if (str == '_')
		return (1);
	return (0);
}
