/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/29 11:46:49 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_color(float x, float input_min, float input_max)
{
	return ((x - input_min) / (input_max - input_min) * 255);
}

int	gen_trgb(int opacity, int red, int green, int blue)
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
		color = gen_trgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
				map_color(t, 0, 63.75));
	}
	else if (t <= 127.5)
	{
		t -= 63.75;
		color = gen_trgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
				map_color(t, 0, 63.75));
	}
	else if (t <= 191.25)
	{
		t -= 127.5;
		color = gen_trgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
				map_color(t, 0, 63.75));
	}
	else
	{
		t -= 191.25;
		color = gen_trgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
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
	return (gen_trgb(255, red, green, blue));
}

void	default_pallete(t_win *main, int inte, int x, int y)
{
	printf("Default Being Called\n");
	int		num_colors;
	int		index1;
	int		index2;
	double	t;
	int		color1;
	int		color2;
	int		color;

	// Define the colors
	int colors[] = {
		0x42300F, // brown 3
		0x19071A, // dark violet
		0x09012F, // darkest blue
		0x040449, // blue 5
		0x000764, // blue 4
		0x0C2C8A, // blue 3
		0x1852B1, // blue 2
		0x397DD1, // blue 1
		0x86B5E5, // blue 0
		0xD3ECF8, // lightest blue
		0xF1E9BF, // lightest yellow
		0xF8C95F, // light yellow
		0xFFAA00, // dirty yellow
		0xCC8000, // brown 0
		0x995700, // brown 1
		0x6A3403  // brown 2
	};
	num_colors = sizeof(colors) / sizeof(colors[0]);
	index1 = inte / (main->interactions / (num_colors - 1));
	index2 = index1 + 1;
	if (index2 >= num_colors)
		index2 = num_colors - 1;
	t = (double)(inte % (main->interactions / (num_colors - 1)))
		/ (main->interactions / (num_colors - 1));
	color1 = colors[index1];
	color2 = colors[index2];
	color = interpolate_color(t, color1, color2);
	place_pixel(main, x, y, color);
}
