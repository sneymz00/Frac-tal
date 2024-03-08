/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:47:53 by camurill          #+#    #+#             */
/*   Updated: 2024/02/21 14:06:31 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countnum(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static int	ft_countunnum(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static int	eastter_egg(int n)
{
	if (n == 0)
		return (ft_characther('0'));
	else
		return (ft_string("-2147483648"));
}

int	ft_number(int n)
{
	char	index;
	int		size;

	index = 0;
	size = ft_countnum(n);
	if (n == 0 || n == -2147483648)
		return (eastter_egg(n));
	if (n < 0)
	{
		if (ft_characther('-') < 0)
			return (-1);
		size += 1;
		n *= (-1);
	}
	if (n > 9 && ft_number(n / 10) < 0)
		return (-1);
	index = n % 10 + '0';
	if (ft_characther(index) < 0)
		return (-1);
	return (size);
}

int	ft_unsigned_number(unsigned int n)
{
	int	index;
	int	size;

	index = 0;
	size = ft_countunnum(n);
	if (n == 0)
		return (ft_characther('0'));
	if (n > 9 && ft_unsigned_number(n / 10) < 0)
		return (-1);
	index = n % 10 + '0';
	if (ft_characther(index) < 0)
		return (-1);
	return (size);
}
/*
int main(void)
{
	int i;
	i = ft_unsigned_number(1687);
	printf("\ni: %d\n", i);
	return (0);
}
*/
