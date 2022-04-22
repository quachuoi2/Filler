/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:56:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/21 07:19:50 by qnguyen          ###   ########.fr       */
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

int	ft_putfloat_fd(long double lift, int prec, int fd)
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
	ft_putnbr_fd(main_num, fd);
	if (prec)
	{
		write(fd, ".", 1);
		while (prec-- > i)
			write(fd, "0", 1);
		if (!lift)
			while (prec-- >= 0)
				write(fd, "0", 1);
		else
			ft_putnbr_fd((long long)lift, fd);
	}
	return (!temp);
}
