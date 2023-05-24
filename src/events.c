/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/24 22:36:31 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_program(t_win *screen)
{
	mlx_destroy_window(screen->mlx_ptr, screen->win_ptr);
	ft_printf("%sProgram closed with success\n%s", BHGRN, RESET);
	exit(1);
}

void	mandelbro_calculation(t_win *screen, int max)
{
	int	inte;

	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			inte = ft_fractal_mandelbrot(screen, max, x, y);
			color_palette(screen, inte, x, y);
		}
	}
}

void	julia_calculation(t_win *screen, int max)
{
	int	inte;

	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			inte = ft_fractal_julia(screen, max, x, y);
			color_palette(screen, inte, x, y);
		}
	}
}

int	key_hook(int keycode, t_win *window)
{
	if (keycode == ESC)
		close_program(window);
	return (0);
}