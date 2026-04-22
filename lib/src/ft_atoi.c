/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:02:02 by aialonso          #+#    #+#             */
/*   Updated: 2026/04/22 18:08:11 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		signo;
	int		num;

	signo = 1;
	num = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signo = signo * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (!(*(nptr + 1) >= '0' && *(nptr + 1) <= '9'))
		{
			num = num * 10 + (*nptr - '0');
			return (signo * num);
		}
		else
			num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (0);
}

/* int	main(int argv, char	**argc)
{
	printf("mi funcion: %d\n", ft_atoi(argc[1]));
	printf("original:   %d\n", atoi(argc[1]));
	return (0);
}
 */