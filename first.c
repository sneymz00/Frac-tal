/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:14:30 by camurill          #+#    #+#             */
/*   Updated: 2024/03/28 14:53:55 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libreries/minilibx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void dibujarfractorl(t_data *data)
{
	int x = 400;
	int y = 400;

	while (x < 500)
	{
		y = 400;
		while (y < 500)
		{
			my_mlx_pixel_put(data, x, y, 0xff0000);
			y++;
		}
		x++;
	}

}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	photo;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	photo.img = mlx_new_image(mlx, 1920, 1080);
	photo.addr = mlx_get_data_addr(photo.img, &photo.bits_per_pixel,
								&photo.line_length, &photo.endian);
	dibujarfractorl(&photo);
	mlx_put_image_to_window(mlx, mlx_win, photo.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}