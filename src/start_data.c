/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/31 21:55:13 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int	initialize_data(t_win *screen)
{
	screen->mlx_ptr = NULL;
	screen->win_ptr = NULL;
	screen->interactions = 150;
	screen->zoom = 1;
	screen->ratio_x = 0;
	screen->ratio_y = 0;
	screen->real_part = 0;
	screen->imaginary_part = 0;
	screen->constant_b = 0;
	screen->constant_b = 0;
	screen->mouse_x = 150;
	screen->mouse_y = 150;
	screen->color_mode = BLACK_AND_WIRTE;
	if (screen->option == 1)
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
