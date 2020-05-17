/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:07:10 by ybesbes           #+#    #+#             */
/*   Updated: 2020/05/17 16:18:27 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size;
	char		*ptr;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return ((char *)s1);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_strchr(set, s1[size]))
		size--;
	ptr = malloc(sizeof(*ptr) * (size + 1 + 1));
	if (ptr != NULL)
	{
		ptr = ft_substr(s1, 0, size + 1);
	}
	return (ptr);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	printf("%s\n",ft_strtrim("", "c"));
}*/
