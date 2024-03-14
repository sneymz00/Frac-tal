/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:35:26 by camurill          #+#    #+#             */
/*   Updated: 2024/02/21 14:09:20 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_selector(va_list args, const char places)
{
	int	size;

	size = 0;
	if (places == 'c')
		size += ft_characther(va_arg(args, int));
	else if (places == 's')
		size += ft_string(va_arg(args, char *));
	else if (places == 'd' || places == 'i')
		size += ft_number(va_arg(args, int));
	else if (places == 'u')
		size += ft_unsigned_number(va_arg(args, unsigned int));
	else if (places == 'x' || places == 'X')
		size += ft_hexadecimal(va_arg(args, unsigned int), places);
	else if (places == 'p')
	{
		size += ft_string("0x");
		if (size < 0)
			return (-1);
		size += ft_voidpointer(va_arg(args, unsigned long));
	}
	else if (places == '%')
		size += ft_characther('%');
	else
		size += ft_characther(places);
	return (size);
}

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, placeholders);
	while (placeholders[i])
	{
		if (placeholders[i] == '%')
		{
			size += ft_selector(args, placeholders[i + 1]);
			i++;
		}
		else
			size += ft_characther(placeholders[i]);
		if (size < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (size);
}
/*
int main()
{
	unsigned long n = 746546672671276;
	unsigned int x = -1;
	int d = -155;
	char c ='c';
	char s[] = "string";
	int lg;
	//lg = ft_printf("hola %i", d);
	lg = ft_printf("Hola, %p, %c, %i, %d, %u, %x ,%X, %s, %%", n, c, d, d);
	lg = ft_printf("Hola,  %x ,%X, %s, %%", x, x, s);
	printf("\n%i", lg);
	return (0);
}
*/