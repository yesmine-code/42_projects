/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:07:08 by ybesbes           #+#    #+#             */
/*   Updated: 2020/06/16 14:18:46 by ybesbes          ###   ########.fr       */
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

	*bytes_read = read(fd, tmp, BUFFER_SIZE);
	if (*bytes_read > 0)
	{
		tmp[*bytes_read] = '\0';
		if (buf == NULL)
			result = ft_strdup(tmp);
		else
			result = ft_strjoin(buf, tmp);
		free(buf);
		buf = result;
	}
	return (buf);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf;
	char		*tmp;
	int			bytes_read;
	int			line_length;

	if (fd < 0 || line == NULL)
		return (-1);
	while (buf == NULL || (!(ft_strchr(buf, '\n'))))
	{
		buf = append_buf(fd, buf, &bytes_read);
		if (bytes_read == 0)
		{
			if (!buf || ft_strlen(buf) == 0)
				return (0);
			else
			{
				*line = ft_strdup(buf);
				buf = NULL;
				return (1);
			}	
		}
		else if (bytes_read == -1)
			return (to_free(buf));
	}
	line_length = ft_strchr(buf, '\n') - buf;
	tmp = ft_substr(buf, 0, line_length);
	*line = tmp;
	tmp = ft_strdup(ft_strchr(buf, '\n') + 1);
	free(buf);
	buf = tmp;
	return (1);
}
