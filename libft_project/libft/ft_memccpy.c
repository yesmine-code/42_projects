/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:48:44 by ybesbes           #+#    #+#             */
/*   Updated: 2020/04/30 22:53:49 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	unsigned char	*dest_local;
	unsigned char	*src_local;

	i = 0;
	dest_local = (char *)dest;
	src_local = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dest_local[i] = src_local[i];
		if (src_local[i] == (unsigned char)c)
			return ((unsigned char *)(dest_local + i + 1));
		i++;
	}
	return (NULL);
}
