/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:14:04 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/19 19:00:35 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (src[n])
	{
		if (dstsize != 0)
		{
			if (n < dstsize - 1)
			{
				dst[n] = src[n];
				i++;
			}
		}
		n++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (n);
}
