/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:50:38 by ybesbes           #+#    #+#             */
/*   Updated: 2020/05/03 22:40:49 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ptr;
	char	*str;

	i = 0;
	ptr = (char *)s1;
	str = (char *)s2;
	while (i < n)
	{
		if (ptr[i] > str[i])
			return (1);
		else if (ptr[i] < str[i])
			return (-1);
		i++;
	}
	return (0);
}
