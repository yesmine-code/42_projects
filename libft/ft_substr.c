/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 02:46:13 by ybesbes           #+#    #+#             */
/*   Updated: 2020/05/14 22:10:46 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL || len == 0 || s[start] == '\0')
		return (NULL);
	i = 0;
	ptr = malloc(sizeof(*ptr) * (len + 1));
	if (ptr != NULL)
	{
		while (i < len && s[start] != '\0')
		{
			ptr[i] = s[start];
			i++;
			start++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
