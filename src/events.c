/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/29 11:47:34 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_pallete(t_win *screen)
{
	printf("Change Pallete Function Called\nPallete Mod %i\n",
			screen->color_mode);
	if (screen->color_mode + 1 < 2)
		screen->color_mode += 1;
	else
		screen->color_mode = 0;
	fracta_builder(screen);
	update_image_display(screen);
}

int	key_hook(int keycode, t_win *window)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC || keycode == 65307)
		close_program(window);
	if (keycode == 65451)
		window->interactions += 10;
	if (keycode == 65455)
		window->interactions -= 10;
	if (keycode == 49)
		change_pallete(window);
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
		fracta_builder(window);
		update_image_display(window);
	}
	return (0);
}