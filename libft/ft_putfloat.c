/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:39:42 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/21 07:19:43 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	number_rounding(int *temp, int *i, long long *main_num,
		long double *lift)
{
	*temp = ft_diglen((long long)*lift);
	if (*lift - (long long)*lift >= 0.5)
		(*lift)++;
	*i = ft_diglen((long long)*lift);
	if (*i > *temp)
	{
		(*main_num)++;
		*lift = 0;
		*temp = (*main_num) % 10;
	}
}

int	ft_putfloat(long double lift, int prec)
{
	long long	main_num;
	int			i;
	int			temp;

	main_num = (long long)lift;
	lift -= main_num;
	if (lift < 0)
		lift *= -1;
	i = 0;
	while (i++ < prec)
		lift *= 10;
	number_rounding(&temp, &i, &main_num, &lift);
	ft_putnbr(main_num);
	if (prec)
	{
		write(1, ".", 1);
		while (prec-- > i)
			write(1, "0", 1);
		if (!lift)
			while (prec-- >= 0)
				write(1, "0", 1);
		else
			ft_putnbr((long long)lift);
	}
	return (!temp);
}
