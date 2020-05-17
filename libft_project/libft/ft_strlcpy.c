/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:20:08 by ybesbes           #+#    #+#             */
/*   Updated: 2020/05/17 15:42:36 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
		if (*src == '\0')
			break ;
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
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%zu\n", strlcpy("mohamed besbes", "yesmine", 0));
	printf("%zu\n", ft_strlcpy("mohamed besbes", "yesmine", 0));
}*/
