/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:01:52 by camurill          #+#    #+#             */
/*   Updated: 2024/05/30 13:26:08 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_fractal(t_fractal fractal)
{
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
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
