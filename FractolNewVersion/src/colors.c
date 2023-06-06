/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/05 12:30:55 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Set Pattern Function:
	-> Reinitializes the MLX image and changes the color pattern.
	-> The fractal can then be rendered again with different color
	-> effects.
*/



void set_pattern(t_fractal *all)
{
	int alt_color = 0;
	all->palete = all->palete + 1 % 9;
	reset_img(all);
	if(all->color == 0x000000)
		alt_color = 0x333333;
	else
		all->color = all->color;
	if(all->color_pattern == 0)
		set_monocromatic_color(all, alt_color);
	else if (all->color_pattern == 3)
		rainbow_set_color(all, (int [4]){0x000000, alt_color,
			convert_color_to_percent(all->color, 50), 0xFFFFFF}, 4);
	else
		color_mode(all);
}

