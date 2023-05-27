/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/27 19:03:55 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_win *window)
{
	if (keycode == ESC || keycode == 65307)
		close_program(window);
	if (keycode == 109)
		window->interactions += 10;
	if (keycode == 110)
		window->interactions -= 10;
	if (window->option == 1)
	{
		if (keycode == 65362)
			window->constant_b += 0.01;
		if (keycode == 65364)
			window->constant_b -= 0.01;
		if (keycode == 65361)
			window->constant_a += 0.01;
		if (keycode == 65363)
			window->constant_a -= 0.01;
		julia_calculation(window);
		update_image_display(window);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_win *window)
{
	if (button == 4)
		zoom_in(window, x, y);
	if (button == 5)
		zoom_out(window, x, y);
	if (window->option == 0)
		mandelbro_calculation(window);
	if (window->option == 1)
		julia_calculation(window);
	(void)x;
	(void)y;
	update_image_display(window);
	return (0);
}
