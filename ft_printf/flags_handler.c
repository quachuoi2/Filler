/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:42:06 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/21 07:18:05 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hash_pos_spc(void)
{
	if (g_order.hash > 0)
	{
		if (g_order.conv == 'b')
			write(g_order.fd, "0b", 2);
		else if (g_order.conv == 'X')
			write(g_order.fd, "0X", 2);
		else if (g_order.conv == 'x' || g_order.conv == 'p')
			write(g_order.fd, "0x", 2);
		else if (g_order.conv == 'o')
			write(g_order.fd, "0", 1);
		return (2 - (g_order.conv == 'o' || g_order.conv == 'f'));
	}
	if (g_order.conv == 'd' || g_order.conv == 'f')
	{
		if (g_order.pos)
			write(g_order.fd, "+", 1);
		else if (g_order.space)
			write(g_order.fd, " ", 1);
		return ((g_order.pos || g_order.space)
			* (g_order.conv == 'd' || g_order.conv == 'f'));
	}
	return (0);
}

int	cal_zero(int length)
{
	int	zero;

	if (g_order.num_of_zeros != 0)
		return (0);
	zero = g_order.mfw - (g_order.pos || g_order.space)
		- length - g_order.negative_num;
	if (!g_order.prec)
	{
		if (g_order.hash == 1 && g_order.conv == 'o')
			zero -= 1;
		else if (g_order.hash == 1)
			zero -= 2;
	}
	else
	{
		if (g_order.mfw > g_order.prec && g_order.conv != 'f')
				zero = g_order.mfw - length;
		else if (g_order.mfw <= g_order.prec)
			zero = g_order.prec - length;
	}
	g_order.num_of_zeros = (zero > 0) * zero;
	return (g_order.num_of_zeros);
}

int	cal_padding(int length)
{
	int	padding;

	padding = 0;
	padding = g_order.mfw - (g_order.pos || g_order.space)
		- length - g_order.negative_num;
	if (g_order.prec > length && g_order.conv != 's')
		padding -= g_order.prec - length;
	if (g_order.hash == 1 && g_order.conv == 'o')
		padding -= 1;
	else if (g_order.hash == 1)
		padding -= 2;
	g_order.num_of_padding = (padding > 0) * padding;
	return (g_order.num_of_padding);
}

int	mfw(int length, int (*f)(void))
{
	int	i;

	i = 0;
	if (length < g_order.mfw || length < g_order.prec)
	{
		if ((g_order.zero || g_order.mfw < g_order.prec)
			&& g_order.conv != 's' && g_order.conv != 'c')
		{
			if (f)
				i += f();
			if (g_order.conv == 'o')
				length += i;
			i += cal_zero(length);
			return (i);
		}
		i += cal_padding(length);
		if (!g_order.neg)
			put_flag(g_order.num_of_padding, ' ', g_order.fd);
	}
	if (f)
		i += f();
	return (i);
}
