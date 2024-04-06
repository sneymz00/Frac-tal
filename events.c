/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:52:34 by camurill          #+#    #+#             */
/*   Updated: 2024/04/06 19:26:16 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*CLOSE FUNTION PRESS ESC*/

int	close_funtion(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

/*
 * KeyPress arquetype 
 * Funtions to move map 
*/
int  key_handler(int key, t_fractal *fractal)
{
	if (key == KEY_ESC)
		close_funtion(fractal);
	else if (key == KEY_UP || key == KEY_W)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (key == KEY_DOWN || key == KEY_S)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (key == KEY_RIGHT || key == KEY_D)
		fractal->shift_x  -= (0.5 * fractal->zoom);
	else if (key == KEY_LEFT || key == KEY_A)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (key == KEY_PLUS)
		fractal->iterations_defintion += 10;
	else if (key == KEY_MINUS)
		fractal->iterations_defintion -= 10;
	else if (key == KEY_Q)
		fractal->zoom *= 1.05;
	else if (key == KEY_E)
		fractal->zoom *= 0.95;
	//refresh
	fractal_render(fractal);
	return (0);
	//if (key == )
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == M_DOWN)
		fractal->zoom *= 1.05;
	else if (button == M_UP)
		fractal->zoom *= 0.95;
	//refresh_render(fractal);
	fractal_render(fractal);
	return (0);
}

//int mouse_event(int )

int	track_julia(int x, int y, t_fractal *fractal)
{
	fractal->julia_x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom)+ fractal->shift_x;
	fractal->julia_y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom)+ fractal->shift_y;
	fractal_render(fractal);
	return (0);
}
