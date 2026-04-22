/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:02:02 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/19 18:41:19 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlencar(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

size_t	conwor(const char *s, char c)
{
	size_t	n;
	size_t	count;

	n = 0;
	count = 0;
	while (s[n])
	{
		if (!(ft_strchr(&s[n], c) == &s[n]))
		{
			count++;
			n = n + ft_strlencar(&s[n], c) - 1;
		}
		n++;
	}
	return (count);
}

void	*freedi(char **ptr, size_t count)
{
	while (count > 0)
	{
		free(ptr[count]);
		count--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	size_t	b;
	char	**ptr;

	n = 0;
	b = conwor(s, c);
	ptr = malloc(sizeof(char *) * (b + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[b] = NULL;
	if (!s)
		return (NULL);
	while (s[n])
	{
		if (!(ft_strchr(&s[n], c) == &s[n]))
		{
			ptr[conwor(s, c) - b] = ft_substr(&s[n], 0, ft_strlencar(&s[n], c));
			if (ptr[conwor(s, c) - b] == NULL)
				return (freedi(ptr, conwor(s, c) - b));
			n = n + ft_strlencar(&s[n], c) - 1;
			b--;
		}
		n++;
	}
	return (ptr);
}

/* 
int	main(void)
{
	char	**ptr;
	char	*string = "\0aa\0bbb";

	ptr = ft_split(string, '\0');
	printf("primera palabra %s\n", ptr[0]);
	printf("primera palabra %s\n", ptr[1]);
	printf("primera palabra %s\n", ptr[2]);
	printf("primera palabra %s\n", ptr[3]);
	printf("primera palabra %s\n", ptr[4]);
	return (0);
} */