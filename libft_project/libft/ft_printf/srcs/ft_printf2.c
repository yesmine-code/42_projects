/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:35:15 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/10 20:59:34 by ybesbes          ###   ########.fr       */
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
	int		signed_arg;
	unsigned int	unsigned_arg;

	if (flags.specifier == 'd' || flags.specifier == 'i')
		return (ft_itoa(va_arg(list, int), "0123456789"));
	if (flags.specifier == 'u')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789"));
	if (flags.specifier == 'x')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789abcdef"));
	if (flags.specifier == 'X')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789ABCDEF"));
	if (flags.specifier == 'o')
		return (ft_itoa(va_arg(list, unsigned int), "01234567"));
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
	printf("\n%o , %u, %x, %X\n", -200, -200, -200, -200);
	ft_printf("\n%o , %u, %x, %X\n", -200, -200, -200, -200);
	printf("\n%e , %E, %e, %E\n", -200, -200, 3.2, 3.2);
	//ft_printf("yesmine %*dbesbes %xyyyy%X",3, 5, -15, -200);
	return (0);
}
