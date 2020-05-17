/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:49:48 by ybesbes           #+#    #+#             */
/*   Updated: 2020/05/03 17:56:05 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_local;
	char	*src_local;

	i = 0;
	dest_local = (char *)dest;
	src_local = (char *)src;
	if (src_local < dest_local)
	{
		while (i++ <= n)
		{
			dest_local[n - i] = src_local[n - i];
		}
	}
	else
	{
		while (i < n)
		{
			dest_local[i] = src_local[i];
			i++;
		}
	}
	return (dest);
}
