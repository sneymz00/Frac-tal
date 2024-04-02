/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:00:14 by camurill          #+#    #+#             */
/*   Updated: 2024/04/02 20:21:33 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if  (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (NULL == s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

double	ft_dbatoi(char *str)
{
	int		value;
	long	number;
	double	decimal;
	double	dec;

	value = 1;
	number = 0;
	decimal = 0;
	dec = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			value *= -1;
		str++;
	}
	while (*str != '.'  && *str)
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (*str)
	{
		dec /= 10;
		decimal = decimal + (*str - '0') * dec;
		str++; 
	}
	return ((number + decimal) * value);
}