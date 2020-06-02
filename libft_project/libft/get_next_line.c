/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:07:08 by ybesbes           #+#    #+#             */
/*   Updated: 2020/06/02 18:43:54 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>

char	*ft_realloc(char *ptr, size_t size)
{
	char	*ptr2;

	ptr2= malloc( sizeof(ptr) + size);
	ft_strlcpy(ptr2, ptr, ft_strlen(ptr) + 1);
	free(ptr);
	return (ptr2);
}
int	get_next_line(int fd, char **line)
{
	int BUFFER_SIZE = 4;
	static char	*buf;
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
//	buf = NULL;
	while (1)
	{
		if (buf == NULL)
		{
			printf("1- buffer est null\n");
			buf = malloc(BUFFER_SIZE);
			read(fd, buf, BUFFER_SIZE);
		}
		else if (buf != NULL && ft_strchr(buf, '\n') == NULL)
		{
			printf("2- pas de retour\n");
			printf("\n%s\n", buf);
			buf = ft_realloc(buf, BUFFER_SIZE);
			printf("sizeof devient %lu, buf devien %s\n", sizeof(buf), buf);
			read(fd, buf + ft_strlen(buf), BUFFER_SIZE);
			printf("sizeof devient %lu, buf devien %s\n", sizeof(buf), buf);
		}
		else
		{
			printf("3- buffer est");
			printf("\n%s\n", buf);
			int s = ft_strchr(buf, '\n') - buf;
			*line = ft_substr(buf, 0, s);
			printf("\nline:\n%s\n", *line);
			tmp = ft_strdup(ft_strchr(buf, '\n') + 1);
			free(buf);
			buf = tmp;
			printf("buffer devient: \n%s" , buf);
			break;
		}

	}
	return (0);
}

int main(void)
{
	char	**ptr;

	ptr = malloc(21);
	int fd = open("text.txt", O_RDONLY);
	get_next_line(fd, ptr);
	get_next_line(fd, ptr + 1);
	get_next_line(fd, ptr + 2);
	get_next_line(fd, ptr + 3);
	close(fd);
	return (0);
}
