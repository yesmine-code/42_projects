/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:25:06 by ybesbes           #+#    #+#             */
/*   Updated: 2020/05/18 02:51:47 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cnumb(const char *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (s == '\0' || *s == '\0')
		return (-1);
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
	ptr[j++] = ft_substr(str, n, i - 1 - n);
	if (ft_check(ptr, j - 1) == 0)
		return (NULL);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*s_trim;
	int		length;

	if (s == NULL)
		return (NULL);
	s_trim = ft_strtrim(s, &c);
	length = cnumb(s_trim, c) + 1 + 1;
	if (length == 2)
		ptr = malloc(sizeof(char**) * length);
	else
		ptr = malloc(sizeof(char**) * length + 1);
	if (ptr != NULL && length > 2)
		ptr = ft_splitter(s_trim, ptr, c);
	else if (ptr != NULL)
		ptr[0] = s_trim;
	if (ptr != NULL)
		ptr[length - 1] = NULL;
	return (ptr);
}
/*
#include <stdio.h>
int main()
{
    char **str;
    char **ptr;
    char **s;

    str = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ult
ricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
    ptr = ft_split("QGOeKvira6BZ Qn3 vhwSrkx MV2z w5OnjQxWS6cY 49KgCnRQhJzTv 5Xt9 NH6Ly1pTS2U8n3 r8bKxLgmFDacPf9 EPAZyD69QiY2lxMb 6F8BkquZn1v0zma S0AFcvwHx3K 
erFCbau5qZos uETnkRtFWKq3PXme", ' ');
    s = ft_split("tC4qEeYLP5uzk SP5 OFrVXauS07N39fn OB0SUkP PtTDZCAh7NI4dcoaj bkgLqH5EW6h KSl2NCgZh 9wGf ELi41Fvg0 SAD5IF", ' ');
    while (*str)
    {
        printf("%s\n", *str);
        str++;
    }
    printf("\n");
    while (*ptr)
    {
        printf("%s\n", *ptr);
        ptr++;
    }
    printf("\n");
    while (*s)
    {
        printf("%s\n", *s);
        s++;
    }
}*/
