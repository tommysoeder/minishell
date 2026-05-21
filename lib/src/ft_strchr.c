/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:43:49 by aialonso          #+#    #+#             */
/*   Updated: 2026/05/21 13:56:01 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	n;

	n = 0;
	while (s[n])
	{
		if (s[n] == (unsigned char)c)
			return (&((char *)s)[n]);
		n++;
	}
	if ((unsigned char)c == '\0')
		return (&((char *)s)[n]);
	return (0);
}
