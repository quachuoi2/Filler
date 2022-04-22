/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:04:41 by qnguyen           #+#    #+#             */
/*   Updated: 2021/12/08 21:55:16 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lststrsplit(const char *s, char c)
{
	t_list	*lst;
	char	*buf;
	t_index	index;

	lst = NULL;
	buf = (char *)ft_memalloc(sizeof(char) * ft_strlen(s));
	if (buf == NULL)
		return (NULL);
	index.i = 0;
	while (index.i <= (int)ft_strlen(s))
	{
		index.j = 0;
		while ((s[index.i] != c) && s[index.i] != '\0')
			buf[index.j++] = s[index.i++];
		buf[index.j] = '\0';
		if (buf[0] != '\0')
			ft_lstadd_back(&lst, ft_lstnew(buf, ft_strlen(buf) + 1));
		index.i++;
	}
	free(buf);
	return (lst);
}
