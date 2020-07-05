/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 20:03:30 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/05 22:31:15 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
struct 	s_flags
{
	char *flags;
	char *width;
	char *precision;
	char *length;
	char specifier
}		t_flags;
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, int len);
int		ft_isdigit(int c);
char	*ft_strchr(char const *s, int c);

char	*get_flags(char *format, int *i)
{
	char	tab[6] = {'-', '+', ' ', '#', '0', 0};
	int		start;
	int		offset;

	offset = 0;
	start = (int)*i;
	while (ft_strchr(tab, format[*i + offset]))
		offset++;
	*i = *i + offset;
	return (ft_substr(format, start, offset));	
}

char	*get_width(char *format, int *i)
{
	int	start;
	int	offset;

	offset = 0;
	start = (int)*i;
	while (ft_isdigit(format[*i + offset]) == 1 || format[*i + offset] == '*')
		offset++;
	*i = *i + offset;
	return (ft_substr(format, start, offset));
}

char	*get_length(char *format, int *i)
{
	char	tab[4] = {'h', 'l', 'L', 0};
	int		start;
	int		offset;

	offset = 0;
	start = (int)*i;
	while (ft_strchr(tab, format[*i + offset]))
		offset++;
	*i = *i + offset;
	return (ft_substr(format, start, offset));
}

char	get_specifier(char *format, int *i)
{
	char	tab[17] = {'c', 'd', 'i', 'e', 'E', 'f', 'g',
   		'G', 'o', 's', 'u', 'x', 'X', 'p', 'n', '%', 0};
	if (ft_strchr(tab, format[*i]))
		return (format[*i++]);
	return (0);
}

void	ft_parse(char *format, int	*i)
{
	char	*flags;
	char	*width;
	char	*precision;
	char	*length;
	char	specifier;

	flags = get_flags(format, i);
	printf("flags ok %d\n", *i);
	width = get_width(format, i);
	if (format[*i] == '.')
	{
		*i = *i + 1;
		precision = get_width(format, i);
	}
	length = get_length(format, i);
	specifier = get_specifier(format, i);
	printf("flags : %s\n width : %s\n precision : %s\n length : %s\n specifier : %c\n", flags, width, precision, length, specifier);
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char	*format;
	int		i;

	i = 0;
	format = "-4.*d";
	ft_parse(format, &i);
	return (0);
}
