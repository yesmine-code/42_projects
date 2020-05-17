/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:20:08 by ybesbes           #+#    #+#             */
/*   Updated: 2020/05/15 12:40:27 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src[i] == '\0')
		return (0);
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
	else
	{
		*(dest - 1) = '\0';
		return (i + ft_strlen(src));
	}
}
