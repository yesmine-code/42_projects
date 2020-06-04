/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:07:08 by ybesbes           #+#    #+#             */
/*   Updated: 2020/06/04 19:41:35 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>

int		get_matrix_length(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

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
		final_size = size + sizeof(ptr);
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

	if (fd < 0)
		return (-1);
	while (buf == NULL || (!(ft_strchr(buf, '\n'))))
	{
		buf = ft_realloc(buf, BUFFER_SIZE);
		if (buf == NULL)
			return (to_free(buf));
		bytes_read = read(fd, buf + ft_strlen(buf), BUFFER_SIZE);
		if (bytes_read == 0)
			return (0);
		else if (bytes_read == -1)
			return (to_free(buf));
	}
	line_length = ft_strchr(buf, '\n') - buf;
	line[get_matrix_length(line)] = ft_substr(buf, 0, line_length);
	tmp = ft_strdup(ft_strchr(buf, '\n') + 1);
	free(buf);
	buf = tmp;
	return (1);
}

int main()
{
	char *ptr[255];
	int i = 0;
	int fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, ptr) == 1)
		printf("%s\n", ptr[i++]);
	close(fd);
}
