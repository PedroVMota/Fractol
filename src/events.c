/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/24 15:39:29 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_program(t_win *screen)
{
	/* if (screen->formula)
		free(screen->formula);
	if (screen->ratio)
		free(screen->ratio); */
	mlx_destroy_window(screen->mlx_ptr, screen->win_ptr);
	ft_printf("%sProgram closed with success\n%s", BHGRN, RESET);
	exit(1);
}

int	key_hook(int keycode, t_win *window)
{
	// ft_printf("keycode: %d\n", keycode);
	 if (keycode == ESC)
		close_program(window);
	/*if (keycode == RIGHT)
	{
		window->canva->x += 1;
		place_pixel(window, window->canva->x, window->canva->y, gen_trgb(0, 255,
					0, 0));
		update_image_display(window);
	} */
	return (0);
}
