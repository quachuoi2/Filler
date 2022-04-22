/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 05:48:16 by qnguyen           #+#    #+#             */
/*   Updated: 2021/12/09 20:27:01 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		c;

	c = ft_diglen(n);
	s = (char *)malloc(sizeof(char) * (c + 1 + 1));
	if (s == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
		c++;
	}
	s[c--] = '\0';
	while (n / 10 > 0)
	{
		s[c--] = (n % 10) + '0';
		n = n / 10;
	}
	s[c] = n + '0';
	return (s);
}
