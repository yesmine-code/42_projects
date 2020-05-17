/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:25:06 by ybesbes           #+#    #+#             */
/*   Updated: 2020/05/17 22:12:45 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cnumb(const char *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
		{
			k++;
		}
		i++;
	}
	return (k);
}

void	free_all(char **ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int		ft_check(char **ptr, int j)
{
	if (ptr[j] == NULL)
	{
		free_all(ptr, j);
		return (0);
	}
	return (1);
}

char	**ft_splitter(char *str, char **ptr, char c)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	n = 0;
	j = 0;
	while (str[i++] != '\0')
	{
		if (str[i] == c && i - n > 0)
		{
			ptr[j++] = ft_substr(str, n, i - n);
			if (ft_check(ptr, j - 1) == 0)
				return (NULL);
			n = i + 1;
		}
		else if (str[i] == c && i - n <= 0)
			n++;
	}
	ptr[j++] = ft_substr(str, n, i - n);
	if (ft_check(ptr, j - 1) == 0)
		return (NULL);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*s_trim;
	int		length;

	s_trim = ft_strtrim(s, &c);
	length = cnumb(s_trim, c) + 1 + 1;
	ptr = malloc(sizeof(char**) * length + 1);
	if (ptr != NULL)
		ptr = ft_splitter(s_trim, ptr, c);
	if (ptr != NULL)
		ptr[length - 1] = NULL;
	return (ptr);
}
