/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squeare_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:36:04 by camurill          #+#    #+#             */
/*   Updated: 2024/03/14 16:54:27 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*
 *	square
 *	(-2, 2)
 *	MANDELBORT
 *	f(z) = z^2 + c
 *	z initilly  is (0,0)
 *	c is the actual point
 */

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	// First
	z.x = 0.0;
	z.y = 0.0;

	//pixdouble  map(double unscaled num, double new_min, double new_max, double old_min, double old_max)el coordinate and scale
	c.x = map(x, -2, 2, 0, WIDTH);
	c.y = map(y, 2, -2, 0, HEIGHT);

	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(square_complex(z), c);
		// if hypotenuse > 2
		if ((z.x*z.x) + (z.y*z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_defintion);
			my_pixel_put();
			return ;
		}
	}
}
