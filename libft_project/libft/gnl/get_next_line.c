/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:07:08 by ybesbes           #+#    #+#             */
/*   Updated: 2020/06/19 23:05:17 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>

int		to_free(char *ptr)
{
	free(ptr);
	return (-1);
}

char	*append_buf(int fd, char *buf, int *bytes_read)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*result;
	char	tmp_buffer[BUFFER_SIZE + 10000];
	int		offset = 0;

	tmp[0] = 0;
	while(!(ft_strchr(tmp, '\n')) && offset < 10000)
	{
		*bytes_read = read(fd, tmp, BUFFER_SIZE);
		if(*bytes_read > 0)
		{
			tmp[*bytes_read] = '\0';
			ft_strcpy(tmp_buffer + offset, tmp);
			offset += *bytes_read;
		}
		else
			break;
	}
	
	if (offset > 0)
	{
		if (buf == NULL)
			result = ft_strdup(tmp_buffer);
		else
			result = ft_strjoin(buf, tmp_buffer);
		free(buf);
		buf = result;
	}
	return (buf);
}

int		ft_case_0(char **buf, char **line)
{
	if (!*buf)
	{
		*line = ft_strdup("");
	}
	else
	{
		*line = ft_strdup(*buf);
		free(*buf);
		*buf = NULL;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf[256];
	char		*tmp;
	int			bytes_read;
	int			line_length;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	while (buf[fd] == NULL || (!(ft_strchr(buf[fd], '\n'))))
	{
		buf[fd] = append_buf(fd, buf[fd], &bytes_read);
		if (bytes_read == 0)
			return (ft_case_0(&buf[fd], line));
		else if (bytes_read == -1)
			return (to_free(buf[fd]));
	}
	line_length = ft_strchr(buf[fd], '\n') - buf[fd];
	*line = ft_substr(buf[fd], 0, line_length);
	tmp = ft_strdup(ft_strchr(buf[fd], '\n') + 1);
	free(buf[fd]);
	buf[fd] = tmp;
	return (1);
}
