/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:12:24 by qnguyen           #+#    #+#             */
/*   Updated: 2021/12/20 05:57:45 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	append_new_line(char **tmp, char (*buf)[BUFF_SIZE + 1], char **line)
{
	char	*s;

	s = ft_strchr(*buf, '\n');
	if (s == NULL)
	{
		*line = ft_strjoin(*tmp, *buf);
		if (*line == NULL)
			return (-1);
		free(*tmp);
		*tmp = *line;
		return (0);
	}
	s = ft_strsub(*buf, 0, s - *buf);
	*line = ft_strjoin(*tmp, s);
	if (*line == NULL)
		return (-1);
	free(*tmp);
	*tmp = *line;
	free(s);
	return (1);
}

static int	temp_handler(char **tmp, char (*buf)[BUFF_SIZE + 1], char **line)
{
	char	*s;

	s = ft_strchr(*buf, '\n') + 1;
	if (s != NULL)
		ft_memmove(*buf, s, ft_strlen(s) + 1);
	if ((*buf)[0] != '\0')
		return (append_new_line(tmp, buf, line));
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char			*tmp;
	static char		buf[FD_SIZE][BUFF_SIZE + 1];
	int				i;

	if (fd < 0 || fd > FD_SIZE || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	tmp = NULL;
	if (buf[fd][0] > 0 && temp_handler(&tmp, &buf[fd], line) == 1)
		return (1);
	i = read(fd, &buf[fd], BUFF_SIZE);
	if (i == -1)
		return (-1);
	while (i > 0)
	{
		buf[fd][i] = '\0';
		if (append_new_line(&tmp, &buf[fd], line) == 1)
			return (1);
		i = read(fd, &buf[fd], BUFF_SIZE);
	}
	if (buf[fd][0] != '\0')
	{
		ft_strclr(buf[fd]);
		return (1);
	}
	return (0);
}
