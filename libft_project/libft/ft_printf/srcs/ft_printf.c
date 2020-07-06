/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 10:40:16 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/06 22:49:30 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

int	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_positif_fd(int n, int fd);
void	ft_putnbr_fd(int n, int fd);

void	ft_printf_int(va_list *my_list)
{
	int num;
	num = va_arg(*my_list, int);
	ft_putnbr_fd(num, 1);
}

void	ft_printf_string(va_list *my_list)
{
	char *src;

	src = va_arg(*my_list, char *);
	write(1, src, ft_strlen(src));
}

void	ft_printf_char(va_list *my_list)
{
	char	c;

	c = va_arg(*my_list, int);
	write(1, &c, 1);
}

int		findindex(char *tab, char element)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	void(*tabfunction[3])(va_list *) = {ft_printf_int, ft_printf_string, ft_printf_char};
	int		i;
	va_list	my_list;
	char	tabindex[4] = {'d', 's', 'c', 0};
	int		tmp;

	tmp = 0;
	va_start(my_list, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (i != 0 && format[i - 1] == '%')
		{
			tmp = findindex(tabindex, format[i]);
			if (tmp != -1)
				(*tabfunction[tmp])(&my_list);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
			write(1, "%", 1);
		else if (format[i] != '%')
			write(1, &format[i], 1);
		i++;
	}
	va_end(my_list);
	return (0);
}

int main()
{
	ft_printf("azerty %s  %c  %d", "qwerty", 'l', 23);
	printf("\n---------\n");
	printf("yesmine");
	return (0);
}
