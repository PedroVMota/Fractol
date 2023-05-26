/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/26 11:03:24 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	initialize_data(t_win *screen, int fractal)
{
	screen->height = HEIGHT;
	screen->width = WIDTH;
	screen->mlx_ptr = NULL;
	screen->win_ptr = NULL;
	screen->image_x = 0;
	screen->image_y = 0;
	screen->offset_x = 1;
	screen->offset_y = 1;
	screen->interactions = 150;
	screen->zoom = 1;
	screen->option = fractal;
	if (fractal == 0)
	{
		screen->mandelbrot = malloc(sizeof(t_mandelbrot));
		if (!screen->mandelbrot)
			return (2);
		screen->mandelbrot->ratio_x = 0;
		screen->mandelbrot->ratio_y = 0;
		screen->mandelbrot->real_part = 0;
		screen->mandelbrot->imaginary_part = 0;
		screen->mandelbrot->constant_b = 0;
		screen->mandelbrot->constant_b = 0;
	}
	else if (fractal == 1)
	{
		screen->julia = malloc(sizeof(t_julia));
		if (!screen->julia)
			return (2);
		screen->julia->ratio_x = 0;
		screen->julia->ratio_y = 0;
		screen->julia->real_part = 0;
		screen->julia->imaginary_part = 0;
		screen->julia->constant_a = -0.8;
		screen->julia->constant_b = 0.156;
	}
	return (0);
}

t_win	*screen(void)
{
	static t_win	screen;

	return (&screen);
}
