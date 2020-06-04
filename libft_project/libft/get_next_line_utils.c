/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:12:16 by ybesbes           #+#    #+#             */
/*   Updated: 2020/06/04 19:44:07 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*ptr;
	size_t		i;

	ptr = str;
	i = 0;
	while (ptr[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(*dest) * (ft_strlen(s) + 1));
	i = 0;
	if (dest != NULL)
	{
		while (s[i] != '\0')
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == NULL)
	{
		dest = NULL;
		return (0);
	}
	while (i < size && *src != '\0')
	{
		*dest++ = *src++;
		i++;
	}
	if (i < size)
	{
		*dest = '\0';
		return (i);
	}
	else if (size > 0)
	{
		*(dest - 1) = '\0';
		return (i + ft_strlen(src));
	}
	else
		return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	i = 0;
	ptr = malloc(sizeof(*ptr) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
