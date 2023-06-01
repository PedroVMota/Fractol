/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_formula.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:46:44 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/01 09:23:22 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static double	map_width(float x, float input_min, int min_range, int max_range)
{
	return (((x - input_min) /
			 (WIDTH - input_min)) *
			 (max_range * screen()->zoom - (-2 * screen()->zoom)) +
			 min_range * screen()->zoom);
}

static double	map_height(float x, float input_min, int min_range, int max_range)
{
	return (((x - input_min) /
			 (HEIGHT - input_min)) *
			 (max_range * screen()->zoom - (-2 * screen()->zoom)) +
			 min_range * screen()->zoom);
}

int	ft_fractal_mandelbrot(t_win *screen, int pixel_x, int pixel_y)
{
	int	interactions;

	interactions = 0;
	screen->ratio_x = map_width(pixel_x, 0, -2, 2);
	screen->ratio_y = map_height(pixel_y, 0, -2, 2);
	screen->constant_a = screen->ratio_x + screen->mouse_x;
	screen->constant_b = screen->ratio_y + screen->mouse_x;
	while (interactions < screen->interactions)
	{
		screen->real_part = screen->ratio_x * screen->ratio_x - screen->ratio_y
			* screen->ratio_y;
		screen->imaginary_part = 2 * screen->ratio_x * screen->ratio_y;
		screen->ratio_x = screen->real_part + screen->constant_a;
		screen->ratio_y = screen->imaginary_part + screen->constant_b;
		if (fabs(screen->ratio_x + screen->ratio_y) > 4.0)
			break ;
		interactions++;
	}
	return (interactions);
}

int	ft_fractal_julia(t_win *screen, int pixel_x, int pixel_y)
{
	int	interactions;

	interactions = 0;
	screen->ratio_x = map_width(pixel_x, 0, -2, 2);
	screen->ratio_y = map_height(pixel_y, 0, -2, 2);
	while (interactions < screen->interactions)
	{
		screen->real_part = screen->ratio_x * screen->ratio_x - screen->ratio_y
			* screen->ratio_y;
		screen->imaginary_part = 2 * screen->ratio_x * screen->ratio_y;
		screen->ratio_x = screen->real_part + screen->constant_a;
		screen->ratio_y = screen->imaginary_part + screen->constant_b;
		if (fabs(screen->ratio_x + screen->ratio_y) > 4.0)
			break ;
		interactions++;
	}
	return (interactions);
}
