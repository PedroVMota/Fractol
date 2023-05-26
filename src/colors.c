/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/26 15:45:50 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void color_palette(t_win *main, int inte, int x, int y)
{
    if (inte >= 0 && inte < 50)
        place_pixel(main, x, y, gen_trgb(0, 0, 0, 0)); // Black
    else if (inte >= 50 && inte < 100)
        place_pixel(main, x, y, gen_trgb(0, 255, 255, 255)); // White
    else if (inte >= 100 && inte < 150)
        place_pixel(main, x, y, gen_trgb(0, 128, 0, 0)); // Maroon
    else if (inte >= 150 && inte < 200)
        place_pixel(main, x, y, gen_trgb(0, 0, 128, 0)); // Green
    else if (inte >= 200 && inte < 250)
        place_pixel(main, x, y, gen_trgb(0, 0, 0, 128)); // Navy
    else if (inte >= 250 && inte < 300)
        place_pixel(main, x, y, gen_trgb(0, 128, 128, 0)); // Olive
    else if (inte >= 300 && inte < 350)
        place_pixel(main, x, y, gen_trgb(0, 255, 165, 0)); // Orange
    else if (inte >= 350 && inte < 400)
        place_pixel(main, x, y, gen_trgb(0, 139, 69, 19)); // Brown
    else if (inte >= 400 && inte < 450)
        place_pixel(main, x, y, gen_trgb(0, 0, 128, 128)); // Teal
    else if (inte >= 450 && inte < 500)
        place_pixel(main, x, y, gen_trgb(0, 0, 0, 0)); // Black (repeated)
    // Add more color ranges and assignments as needed...
    return;
}

