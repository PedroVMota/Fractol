/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/24 22:31:49 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	gen_trgb(int opacity, int red, int green, int blue)
{
	if (opacity > 255 || red > 255 || green > 255 || blue > 255)
		return (0);
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

void	color_palette(t_win *main, int inte, int x, int y)
{
	double red, green, blue;

	if (inte == 300)
	{
		red = green = blue = 0; // Black
	}
	else if (inte < 150)
	{
		red = map(inte, 1, 149, 0, 255);
		green = map(inte, 1, 149, 0, 165);
		blue = 0; // Orange
	}
	else if(inte  == 0)
	{
		red = 255;
		green = map(inte, 150, 300, 165, 255);
		blue = 0; // Bright Orange
	}

	place_pixel(main, x, y, gen_trgb(0, (int)red, (int)green, (int)blue));
}

