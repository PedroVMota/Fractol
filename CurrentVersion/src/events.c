/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/06 00:23:53 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_win *window)
{
	if (keycode == ESC || keycode == 65307)
		close_program(window);
	if (window->set == JULIA)
	{
		if (keycode == 65362)
			window->constant_imaginary += 0.01;
		if (keycode == 65364)
			window->constant_imaginary -= 0.01;
		if (keycode == 65361)
			window->constant_real += 0.01;
		if (keycode == 65363)
			window->constant_real -= 0.01;
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_win *window)
{
	(void)button;
	(void)window;
	(void)x;
	(void)y;
	return (0);
}
