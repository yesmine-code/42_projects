/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:35:15 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/08 19:16:46 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_struct(t_flags flags)
{
	if (flags.flags != NULL)
		free(flags.flags);
	if (flags.width != NULL)
		free(flags.width);
	if (flags.precision != NULL)
		free(flags.precision);
	if (flags.length != NULL)
		free(flags.length);
}

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

char	*read_specifier(t_flags flags, va_list list)
{
	int	arg;

	if (flags.specifier == 'd')
	{
		arg = va_arg(list, int);
		return (ft_itoa(arg));
	}
	return (ft_strdup(""));
}

int		ft_printf(const char *format, ...)
{
	int		i;
	t_flags	flags;
	va_list	list;
	int		star_width_arg;
	int		star_precision_arg;
	char	*specifier;

	i = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			flags = ft_parse(format, &i);
		//	printf("flags.width : %s  flags.precision : %s\n", flags.width, flags.precision);
			star_width_arg = ft_read_star_parameter(flags.width, list);
			star_precision_arg = ft_read_star_parameter(flags.precision, list);
			specifier = read_specifier(flags, list);
			ft_putstr(specifier);
			i++;
			
			free(specifier);
			ft_free_struct(flags);
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
	ft_printf("yesmine %*dbesbes %dyyyy%*4d",3, 5, 6, 7);
	return (0);
}
