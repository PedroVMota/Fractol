/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/29 10:53:01 by pvital-m         ###   ########.fr       */
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
	int	color;

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
	place_pixel(main, x, y, color);
}
