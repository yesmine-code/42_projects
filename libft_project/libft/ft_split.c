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

static int		count_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int		words_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		*leak(char **splitted, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

static char		**fill(char const *s, int words, char c, char **splitted)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = words_len(s, c);
		if (!(splitted[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (leak(splitted, i));
		j = 0;
		while (j < len)
			splitted[i][j++] = *s++;
		splitted[i][j] = '\0';
	}
	splitted[i] = NULL;
	return (splitted);
}

char			**ft_split(char	const *s, char c)
{
	char	**splitted;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!(splitted = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	splitted = fill(s, words, c, splitted);
	return (splitted);
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
