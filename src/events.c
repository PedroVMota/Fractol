/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/22 15:55:52 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_program(t_win *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	ft_printf("%sProgram closed with success\n%s", BHGRN, RESET);
	exit(1);
}

int	key_hook(int keycode, t_win *window)
{
	// ft_printf("keycode: %d\n", keycode);
	if (keycode == ESC)
		close_program(window);
	if (keycode == RIGHT)
	{
		window->canva->x += 1;
		place_pixel(window, window->canva->x, window->canva->y, \
			gen_trgb(0, 255, 0, 0));
		update_image_display(window);
	}
	return (0);
}
