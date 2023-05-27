/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/27 19:36:25 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	initialize_data(t_win *screen, int fractal)
{
	screen->height = HEIGHT;
	screen->width = WIDTH;
	screen->mlx_ptr = NULL;
	screen->win_ptr = NULL;
	screen->image_x = 0;
	screen->image_y = 0;
	screen->offset_x = 1;
	screen->offset_y = 1;
	screen->interactions = 300;
	screen->zoom = 1;
	screen->option = fractal;
	screen->ratio_x = 0;
	screen->ratio_y = 0;
	screen->real_part = 0;
	screen->imaginary_part = 0;
	screen->constant_b = 0;
	screen->constant_b = 0;
	if (fractal == 1)
	{
		screen->constant_a = -0.8;
		screen->constant_b = 0.156;
	}
	return (0);
}

t_win	*screen(void)
{
	static t_win	screen;

	return (&screen);
}
