/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/29 17:53:24 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_color(float x, float input_min, float input_max)
{
	return ((x - input_min) / (input_max - input_min) * 255);
}

int	rgb(int opacity, int red, int green, int blue)
{
	if (opacity > 255 || red > 255 || green > 255 || blue > 255)
		return (0);
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

int	rand_color(void)
{
	int	color;

	color = rand() % 255 + 0;
	return (color);
}

void	zebra_pallete(t_win *main, int inte, int x, int y)
{
	float	t;
	int		color;

	color = 0;
	t = map_color(inte, 0, main->interactions);
	if (t <= 63.75)
	{
		color = rgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
				map_color(t, 0, 63.75));
	}
	else if (t <= 127.5)
	{
		t -= 63.75;
		color = rgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
				map_color(t, 0, 63.75));
	}
	else if (t <= 191.25)
	{
		t -= 127.5;
		color = rgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
				map_color(t, 0, 63.75));
	}
	else
	{
		t -= 191.25;
		color = rgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
				map_color(t, 0, 63.75));
	}
	place_pixel(main, x, y, (color < 0 ? -color : color));
}

int	interpolate_color(double t, int color1, int color2)
{
	int	red;
	int	green;
	int	blue;

	red = (int)((1 - t) * ((color1 >> 16) & 0xFF) + t
			* ((color2 >> 16) & 0xFF));
	green = (int)((1 - t) * ((color1 >> 8) & 0xFF) + t
			* ((color2 >> 8) & 0xFF));
	blue = (int)((1 - t) * (color1 & 0xFF) + t * (color2 & 0xFF));
	return (rgb(255, red, green, blue));
}

void	default_pallete(t_win *main, int inte, int x, int y)
{
	float	t;
	int		color;

	color = 0;
	t = map_color(inte, 0, main->interactions);
	if(t <= 5)
		color = rgb(0, 30, 99, 117);
	else if (t <= 10)
		color = rgb(0, 40, 131, 152);
	else if (t <= 20)
		color = rgb(0, 0, 128, 255);
	else if (t <= 50.00)
		color = rgb(0, 0, 255, 178);
	else if (t <= 100.00)
		color = rgb(0, 255, 219, 0);
	else if (t <= 150)
		color = rgb(0, 255, 64, 0);
	else if (t <= 150)
		color = rgb(0, 255, 64, 0);
	else if (t <= 200)
		color = rgb(0, 136, 255, 0);
	else
		color = rgb(0, 117, 56, 30);
	place_pixel(main, x, y, (color < 0 ? -color : color));
}
