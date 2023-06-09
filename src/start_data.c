/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/09 13:20:26 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_image(t_win *screen)
{
	t_img	local;

	local.img_ptr = NULL;
	local.addr = NULL;
	local.bpp = 0;
	local.line_len = 0;
	local.endian = 0;
	screen->canva = &local;
}

void	initialize_data(t_win *screen)
{
	set_image(screen);
	screen->mlx_ptr = NULL;
	screen->win_ptr = NULL;
	screen->min_r = -2;
	screen->max_r = 2;
	screen->min_i = -2;
	screen->max_i = 2;
	screen->cr = 0;
	screen->ci = 0;
	screen->real_x = 1;
	screen->zoom = 1;
	screen->fraction_x = 1;
	screen->pallete = ZEBRA;
	screen->color = 0xFF1a4c;
}

t_win	*screen(void)
{
	static t_win	screen;

	return (&screen);
}

void	print_data(void)
{
	printf("=========== DATA ===========\n");
	printf("mlx_ptr: %p\n", screen()->mlx_ptr);
	printf("win_ptr: %p\n", screen()->win_ptr);
	printf("min_real: %f\n", screen()->min_r);
	printf("max_real: %f\n", screen()->max_r);
	printf("min_imaginary: %f\n", screen()->min_i);
	printf("max_imaginary: %f\n", screen()->max_i);
	printf("constant_real: %f\n", screen()->cr);
	printf("constant_imaginary: %f\n", screen()->ci);
	printf("scale: %f\n", screen()->zoom);
	printf("real_x: %f\n", screen()->real_x);
	printf("fraction_x: %f\n", screen()->fraction_x);
	printf("pallete: %d\n", screen()->pallete);
	printf("set: %d\n", screen()->set);
	printf("=========== DATA ===========\n");
}
