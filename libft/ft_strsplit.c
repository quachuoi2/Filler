/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:13:47 by qnguyen           #+#    #+#             */
/*   Updated: 2021/12/08 21:53:40 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_failed_malloc(char ***arr, int i)
{
	if ((*arr)[i] == NULL)
	{
		ft_arrdel(arr);
		return (0);
	}
	return (1);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**arr;
	char	*buf;
	t_index	index;

	arr = (char **)ft_memalloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	buf = (char *)ft_memalloc(sizeof(char) * ft_strlen(s));
	if (arr == NULL || buf == NULL)
		return (NULL);
	index.i = 0;
	index.k = 0;
	while (index.i <= (int)ft_strlen(s))
	{
		index.j = 0;
		while ((s[index.i] != c) && s[index.i] != '\0')
			buf[index.j++] = s[index.i++];
		buf[index.j] = '\0';
		if (buf[0] != '\0')
			arr[index.k++] = ft_strdup(buf);
		if (index.k > 0 && check_failed_malloc(&arr, index.k - 1) == 0)
			return (NULL);
		index.i++;
	}
	free(buf);
	return (arr);
}
