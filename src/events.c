/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital@student.42lisbon.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/25 00:03:59 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void close_program(t_win *screen)
{
	mlx_destroy_window(screen->mlx_ptr, screen->win_ptr);
	ft_printf("%sProgram closed with success\n%s", BHGRN, RESET);
	exit(1);
}

int key_hook(int keycode, t_win *window)
{
	ft_printf("Keycode %i\n");
	if (keycode == ESC)
		close_program(window);
	return (0);
}

int key_hook_mouse(int keycode, int x, int y, t_win *param)
{

    printf("Mouse event: Button %d at (%d, %d)\n", keycode, x, y);
    // Perform actions based on the mouse event

    return 0;
}