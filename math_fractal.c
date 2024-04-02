/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:43:23 by camurill          #+#    #+#             */
/*   Updated: 2024/04/02 20:27:21 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double u_num, double n_min, double n_max, double o_min, double o_max)
{
	return (n_max - n_min) * (u_num - o_min) / (o_max - o_min) + n_min;
}

//SUM COMPLEX

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	r;
	
	r.x = z1.x + z2.x;
	r.y = z1.y + z2.y;
	return (r);
}

//SQUARE
// real = (x^2 + y^2)
// i = 2*x*y

t_complex	square_complex(t_complex z)
{
	t_complex	final;

	final.x = (z.x * z.x) - (z.y * z.y);
	final.y = 2 * z.x * z.y;
	return (final);
}
