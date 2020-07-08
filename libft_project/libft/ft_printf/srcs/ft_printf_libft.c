/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:01:10 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/08 19:16:15 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(const char *str)
{
	const char	*ptr;
	int			i;

	ptr = str;
	i = 0;
	while (ptr[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_positif_fd(int n, int fd)
{
	int		a;
	char	c;

	if (n / 10 != 0)
		ft_putnbr_positif_fd(n / 10, fd);
	a = n % 10;
	if (a < 0)
		a = -a;
	c = a + '0';
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_positif_fd(n, fd);
}
