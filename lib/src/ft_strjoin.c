/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:42:00 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/19 22:12:18 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*con;

	if (!s1 || !s2)
		return (NULL);
	len = 1 + ft_strlen(s1) + ft_strlen(s2);
	con = malloc(len * sizeof(char));
	if (con == NULL)
		return (NULL);
	ft_strlcpy(con, s1, ft_strlen(s1) + 1);
	ft_strlcat(con, s2, len);
	return (con);
}
