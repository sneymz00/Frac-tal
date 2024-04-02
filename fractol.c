/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:35:00 by camurill          #+#    #+#             */
/*   Updated: 2024/04/02 20:51:27 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//If malloc goes bad
static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4; // 2 *2 hypotenuse
	fractal->iterations_defintion = 100;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
			2, 0, key_handler, fractal);
	mlx_hook(fractal->mlx_window,
			4, 0, mouse_handler, fractal);	
	mlx_hook(fractal->mlx_window,
			17, 0, close_funtion, fractal);
	mlx_hook(fractal->mlx_window,
			6, 0, track_julia, fractal);	
}

/***INIT***/

void	*fractal_init(t_fractal *fractal)
{
	//MLX stuff
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
										WIDTH,
										HEIGHT,
										fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
										WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		//mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr =  mlx_get_data_addr(fractal->img.img_ptr,
												&fractal->img.bpp,
												&fractal->img.line_len,
												&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
	return (0);
}
