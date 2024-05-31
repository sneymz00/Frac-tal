/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:01:52 by camurill          #+#    #+#             */
/*   Updated: 2024/05/31 16:29:43 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_fractal(t_fractal fractal)
{
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
}

static int	error_syntax(char *str)
{
	if (! ((*str == '+' || *str == '-' )
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-' || *str == '+')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (*str == '.')
			str++;
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

static void	easter_egg(char **av)
{
	if ((error_syntax(av[2]) == 1 || error_syntax(av[3]) == 1))
	{
		write(1, "Please, write a correct number", 31);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 11)))
	{
		fractal.name = av[1];
		set_fractal(fractal);
	}
	else if (4 == ac && !ft_strncmp(av[1], "julia", 6))
	{
		fractal.name = av[1];
		easter_egg(av);
		fractal.julia_x = ft_dbatoi(av[2]);
		fractal.julia_y = ft_dbatoi(av[3]);
		set_fractal(fractal);
	}
	else if (2 == ac && !ft_strncmp(av[1], "tricorn", 9))
	{
		fractal.name = av[1];
		set_fractal(fractal);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
