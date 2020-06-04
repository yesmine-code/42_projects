/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:07:08 by ybesbes           #+#    #+#             */
/*   Updated: 2020/06/04 13:06:02 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>
int	get_matrix_length(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

void	to_free(char **ptr)
{
	char	**tmp;

	tmp = ptr;
	while (*tmp)
	{ 
		free(tmp++);
	}
	//free(ptr);
}

char	*ft_realloc(char *ptr, size_t size)
{
	char	*ptr2;

	if (ptr == NULL)
	{
		ptr = ft_calloc(size, 1);
		return ptr;
	}
	else
	{
		ptr2 = ft_calloc(sizeof(ptr) + size, 1);
		if (ptr2)
			ft_strlcpy(ptr2, ptr, ft_strlen(ptr) + 1);
		free(ptr);
		return ptr2;
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	char		*tmp;
	int		line_length;
	int		bytes_read;

	if (fd < 0)
		return (-1);
	while (buf == NULL || (!(ft_strchr(buf, '\n'))))
	{
		buf = ft_realloc(buf, BUFFER_SIZE);
		if(buf == NULL)
		{
			free(buf);
			return (-1);
		}
		bytes_read = read(fd, buf + ft_strlen(buf), BUFFER_SIZE);
		if (bytes_read == 0) //eof
			return (0);
		else if (bytes_read == -1)
		{
			free(buf);
			return (-1);
		}
	}
	line_length = ft_strchr(buf, '\n') - buf;
	line[get_matrix_length(line)] = ft_substr(buf, 0, line_length);
	tmp = ft_strdup(ft_strchr(buf, '\n') + 1);
	free(buf);
	buf = tmp;
	return (1);
}

int main(void)
{
	char	**ptr;
	int	i;

	i = 0;
	ptr = NULL;
	ptr = malloc(100);
	int fd = open("text.txt", O_RDONLY);
	printf("starting test \n");
	while (get_next_line(fd, ptr) == 1)
	{
		printf("---\n%d: %s\n",i,ptr[i]);
		i++;
	}
	printf("end of the test");
	close(fd);
	return (0);
}
