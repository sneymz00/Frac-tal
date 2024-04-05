/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squeare_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:36:04 by camurill          #+#    #+#             */
/*   Updated: 2024/04/05 14:17:03 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Put a pixel in my image buffer 
*/

static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset =  (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) =  color;
}

static void	choice_matrix(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 6))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
		z->x = 0.0;
		z->y = 0.0;
	}
}

/*
 *	square
 *	(-2, 2)
 *	MANDELBORT
 *	f(z) = z^2 + c
 *	z initilly  is (0,0)
 *	c is the actual point
 */


static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	//if ()
	//z.x = 0.0;
	//z.y = 0.0;
	//pixdouble  map(double unscaled num, double new_min, double new_max, double old_min, double old_max)el coordinate and scale
	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom)+ fractal->shift_x;
	z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom)+ fractal->shift_y;
	//select base
	choice_matrix(&z, &c, fractal);
	//operations
	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(square_complex(z), c);
		// if hypotenuse > 2
		if ((z.x*z.x) + (z.y*z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_defintion);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	//If MANDELBORT given itearations made
	my_pixel_put(x, y, &fractal->img, HOT_PINK);
}
/*
 * 
 * ***SQUARE***
 * 
*/
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							  fractal->mlx_window,
							  fractal->img.img_ptr,
							  0, 0);
}
