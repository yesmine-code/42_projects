/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:35:15 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/06 23:48:12 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_flags
{
	char *flags;
	char *width;
	char *precision;
	char *length;
	char specifier;
}				t_flags;


t_flags	ft_parse(const char *format, int	*i);

int		ft_read_star_parameter(char *flags, va_list list)
{
	int	i;
	int	star_arg;

	i = 0;
	star_arg = -1;
	while (flags[i] != '\0')
	{
		if (flags[i] == '*')
		{
			star_arg = va_arg(list, int);
			break;
		}
		i++;
	}
	return (star_arg);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	t_flags	flags;
	va_list	list;
	int		star_width_arg;
	int		star_precision_arg;

	i = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			flags = ft_parse(format, &i);
			star_width_arg = ft_read_star_parameter(flags.width, list);
			star_precision_arg = ft_read_star_parameter(flags.precision, list);
			printf("star_width =  %d \n star_precision = %d", star_width_arg, star_precision_arg);
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(list);
	return (0);
}

int main()
{
	int a;

	a = 10;
	ft_printf("yesmine %*.*d", 6, 2, a);
	return (0);
}
