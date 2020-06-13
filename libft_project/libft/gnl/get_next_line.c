/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:07:08 by ybesbes           #+#    #+#             */
/*   Updated: 2020/06/14 00:00:57 by ybesbes          ###   ########.fr       */
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

char	*ft_realloc(char *ptr, size_t size)
{
	char	*ptr2;
	int		final_size;
	int		i;

	i = 0;
	if (ptr == NULL)
		final_size = size;
	else
		final_size = size + ft_strlen(ptr) + 1;
	ptr2 = malloc(final_size);
	if (ptr2 != NULL)
	{
		while (i < final_size)
			ptr2[i++] = 0;
		if (ptr)
			ft_strlcpy(ptr2, ptr, ft_strlen(ptr) + 1);
	}
	if (ptr)
		free(ptr);
	return (ptr2);
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
		buf = ft_realloc(buf, BUFFER_SIZE);
		if (buf == NULL)
			return (to_free(buf));
		bytes_read = read(fd, buf + ft_strlen(buf), BUFFER_SIZE);
		if (bytes_read == 0)
		{
			if (ft_strlen(buf) == 0)
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
