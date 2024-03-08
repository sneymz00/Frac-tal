/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:33:10 by camurill          #+#    #+#             */
/*   Updated: 2024/02/21 13:40:17 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>
//#include <unistd.h>

int	ft_characther(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_string("(null)"));
	while (str[i])
	{
		if (ft_characther(str[i]) < 0)
			return (-1);
		i++;
	}
	return (i);
}
/*
int main (void)ß
{
	int i;

	ft_characther('c');
	write(1, "\n", 1);
	i = ft_string("hola");
	printf("\n%i", i);
	return (0);
}
*/