/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/25 09:43:57 by pvital-m         ###   ########.fr       */
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

	if(inte == 0)
		place_pixel(main, x, y, gen_trgb(0,7, 101, 246));
	if(inte < 29)
		place_pixel(main, x, y, gen_trgb(0,110, 20, 153));
	if(inte < 49)
		place_pixel(main, x, y, gen_trgb(0, 255,179,0));
	if(inte < 69)
		place_pixel(main, x, y, gen_trgb(0,154, 171, 73));
	if(inte < 89)
		place_pixel(main, x, y, gen_trgb(0,3, 150, 159));
	if(inte < 101)
		place_pixel(main, x, y, gen_trgb(0,119, 15, 180));
	if(inte < 129)
		place_pixel(main, x, y, gen_trgb(0,21, 51, 169));
	if(inte < 149)
		place_pixel(main, x, y, gen_trgb(0,204, 138, 32));
	if(inte < 169)
		place_pixel(main, x, y, gen_trgb(0,41, 63, 16));
	if(inte < 189)
		place_pixel(main, x, y, gen_trgb(0,70, 46, 128));
	if(inte < 201)
		place_pixel(main, x, y, gen_trgb(0,122, 155, 219));
	if(inte < 229)
		place_pixel(main, x, y, gen_trgb(0,235, 199, 19));
	if(inte < 269)
		place_pixel(main, x, y, gen_trgb(0,204, 138, 32));
	if(inte < 289)
		place_pixel(main, x, y, gen_trgb(0,18, 74, 88));
	if(inte < 300)
		place_pixel(main, x, y, gen_trgb(0,223, 241, 231));
	return ;
}
