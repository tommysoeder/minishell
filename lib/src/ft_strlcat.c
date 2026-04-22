/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:54:02 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/19 22:13:15 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	i;
	size_t	lonsrc;

	n = 0;
	i = 0;
	lonsrc = ft_strlen(src);
	while (dst[n])
		n++;
	if (dstsize <= n)
		return (dstsize + lonsrc);
	while (src[i])
	{
		if (dstsize != 0)
		{
			if (dstsize > (n + i + 1))
				dst[n + i] = src[i];
			else
				break ;
		}
		i++;
	}
	if (dstsize >= n + i)
		dst[n + i] = '\0';
	return (n + lonsrc);
}
/* 
#include <stdio.h>
#include <string.h>
int main()
{
	char *str = "abcdefghi";
 	char buff1[0xF00] = "pqrs";
 	char buff2[0xF00] = "pqrs";
 	size_t max = 10;
 
	//strlcat(buff1, str, max);
 	ft_strlcat(buff2, str, max);
	
	//printf("strlcat   : %s", buff1);
	printf("ft_strlcat: %s", buff2);


	return 0;
} */
