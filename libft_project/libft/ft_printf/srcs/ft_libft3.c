/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:57:15 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/09 17:13:46 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count(int n, char *base)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n / ft_strlen(base) != 0)
	{
		i++;
		n = n / ft_strlen(base);
	}
	return (i + 1);
}

int		check_base(char *base)
{
	int	i;
	int j;

	i = 0;
	j = i + 1;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (-1);
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		i++;
	}
	return (1);
}

char	*ft_itoa(int n, char *base)
{
	char	*str;
	int		j;
	long	nbr;

	j = ft_count(n, base);
	nbr = n;
	str = malloc(sizeof(char) * (ft_count(n, base) + 1));
	if (str != NULL && check_base(base) == 1)
	{
		if (nbr < 0)
		{
			str[0] = '-';
			nbr = nbr * -1;
		}
		while (nbr / ft_strlen(base) != 0 && j >= 0)
		{
			str[j - 1] = base[nbr % ft_strlen(base)];
			nbr = nbr / ft_strlen(base);
			j--;
		}
		str[j - 1] = base[nbr];
		str[ft_count(n, base)] = '\0';
	}
	return (str);
}
