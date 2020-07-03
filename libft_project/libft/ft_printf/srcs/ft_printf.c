/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 10:40:16 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/03 13:32:38 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_isflag(char c)
{
	if (c == ' ' || c == '-' || c == '+'
		   	|| c == '#' || c == '0')
		return (1);
	else
		return (-1);
}

int ft_isspecifier(char c)
{
	if (c == 'c' || c == 'd' || c == 'x' || c == 'X'
			|| c == 'i' || c == 'p' || c == 'e' || c == 'E' || c == 'o' 
			|| c == 'g' || c == 'G' || c == 'f' || c == 's' || c == 'n'
			|| c == 'u' || c == '%')
		return (1);
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else if (format[i] == '%' && format[i + 1] == '%')
			write(1, "%", 1);
		i++;
	}
	return (0);
}

int main()
{
	ft_printf(NULL);
	printf("\n---------\n");
	printf(NULL);
	return (0);
}
