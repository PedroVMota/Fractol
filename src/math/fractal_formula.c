/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_formula.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:46:44 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/27 19:09:57 by pvital-m         ###   ########.fr       */
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
	screen->ratio_x = map(pixel_x + screen->mouse_x, 0, WIDTH);
	screen->ratio_y = map(pixel_y + screen->mouse_y, 0, HEIGHT);
	screen->constant_a = screen->ratio_x;
	screen->constant_b = screen->ratio_y;
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
	screen->ratio_x = map(pixel_x + screen->mouse_x, 0, WIDTH);
	screen->ratio_y = map(pixel_y + screen->mouse_y, 0, HEIGHT);
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
