/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:10:41 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/25 14:16:30 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumeric(char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		if (n == 0 && (str[n] == '-' || str[n] == '+')
			&& ft_isdigit(str[n + 1]))
			n++;
		if (!ft_isdigit(str[n]))
			return (1);
		n++;
	}
	return (0);
}
