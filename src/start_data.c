/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/10 08:38:17 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_mouse(t_win *screen)
{
	t_axis	*local;

	local = malloc(sizeof(t_axis));
	if (!local)
		close_program(screen, "Mouse configuration went wrong!", 2);
	local->mouse_x = 0;
	local->mouse_y = 0;
	screen->mouse = local;
}

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

static void	set_limits_proportional(t_win *screen)
{
	double	aspect_ratio;
	double	max_abs;

	aspect_ratio = (double)WIDTH / HEIGHT;
	max_abs = 2.0;
	if (aspect_ratio > 1.0)
	{
		screen->max_r = max_abs;
		screen->max_i = max_abs / aspect_ratio;
	}
	else
	{
		screen->max_r = max_abs * aspect_ratio;
		screen->max_i = max_abs;
	}
	screen->min_r = -screen->max_r;
	screen->min_i = -screen->max_i;
}

void	initialize_data(t_win *screen)
{
	set_image(screen);
	set_mouse(screen);
	set_limits_proportional(screen);
	screen->n = 150;
	screen->mlx_ptr = NULL;
	screen->win_ptr = NULL;
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
