/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:46:44 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/26 15:45:08 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(float x, float input_min, float input_max)
{
	return (((x - input_min) / (input_max - input_min)) * (2 / screen()->zoom
			- (-2 / screen()->zoom)) + -2 / screen()->zoom);
}

int	ft_fractal_mandelbrot(t_win *screen, int pixel_x, int pixel_y)
{
	int	interactions;

	interactions = 0;
	screen->mandelbrot->ratio_x = map(pixel_x + screen->mouse_x, 0, screen->width);
	screen->mandelbrot->ratio_y = map(pixel_y + screen->mouse_y, 0, screen->height);
	screen->mandelbrot->constant_a = screen->mandelbrot->ratio_x;
	screen->mandelbrot->constant_b = screen->mandelbrot->ratio_y;
	while (interactions < screen->interactions)
	{
		screen->mandelbrot->real_part = pow(screen->mandelbrot->ratio_x, 2)
			- pow(screen->mandelbrot->ratio_y, 2);
		screen->mandelbrot->imaginary_part = 2 * screen->mandelbrot->ratio_x
			* screen->mandelbrot->ratio_y;
		screen->mandelbrot->ratio_x = screen->mandelbrot->real_part
			+ screen->mandelbrot->constant_a;
		screen->mandelbrot->ratio_y = screen->mandelbrot->imaginary_part
			+ screen->mandelbrot->constant_b;
		if (fabs(screen->mandelbrot->ratio_x
				+ screen->mandelbrot->ratio_y) > 4.0)
			break ;
		interactions++;
	}
	return (interactions);
}

int	ft_fractal_julia(t_win *screen, int pixel_x, int pixel_y)
{
	int	interactions;

	interactions = 0;
	screen->julia->ratio_x = map(pixel_x + screen->mouse_x, 0, WIDTH);
	screen->julia->ratio_y = map(pixel_y + screen->mouse_y, 0, HEIGHT);
	while (interactions < screen->interactions)
	{
		screen->julia->real_part = pow(screen->julia->ratio_x, 2)
			- pow(screen->julia->ratio_y, 2);
		screen->julia->imaginary_part = 2 * screen->julia->ratio_x
			* screen->julia->ratio_y;
		screen->julia->ratio_x = screen->julia->real_part
			+ screen->julia->constant_a;
		screen->julia->ratio_y = screen->julia->imaginary_part
			+ screen->julia->constant_b;
		if (fabs(screen->julia->ratio_x + screen->julia->ratio_y) > 4.0)
			break ;
		interactions++;
	}
	return (interactions);
}
