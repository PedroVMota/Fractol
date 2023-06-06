/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/06 00:35:20 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void set_image(t_win *screen)
{
	t_img local;
	local.img_ptr = NULL;
	local.addr = NULL;
	local.bpp = 0;
	local.line_len = 0;
	local.endian = 0;
	screen->canva = &local;
}
void initialize_data(t_win *screen)
{
	set_image(screen);
	screen->mlx_ptr					= NULL;
	screen->win_ptr 				= NULL;
	screen->min_real 				= -2;
	screen->max_real 				= 2;
	screen->min_imaginary 			= -2;
	screen->max_imaginary 			= 2;
	screen->constant_real 			= 0;
	screen->constant_imaginary 		= 0;
	screen->scale 					= 0;
	screen->real_x 					= 0;
	screen->fraction_x 				= 0;
	screen->pallete 				= ZEBRA;
}

t_win *screen(void)
{
	static t_win screen;

	return (&screen);
}
