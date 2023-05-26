/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/26 15:50:24 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_program(t_win *screen)
{
	mlx_destroy_image(screen->mlx_ptr, screen->canva->img_ptr);
	mlx_destroy_window(screen->mlx_ptr, screen->win_ptr);
	mlx_destroy_display(screen->mlx_ptr);
	free(screen->mandelbrot);
	free(screen->julia);
	ft_printf("%sProgram closed with success\n%s", BHGRN, RESET);
	exit(1);
}

void	mandelbro_calculation(t_win *screen)
{
	int	inte;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			inte = ft_fractal_mandelbrot(screen, x, y);
			color_palette(screen, inte, x, y);
			y++;
		}
		x++;
	}
}

void	julia_calculation(t_win *screen)
{
	int	inte;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT + 500)
		{
			inte = ft_fractal_julia(screen, x, y);
			color_palette(screen, inte, x, y);
			y++;
		}
		x++;
	}
}

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
			window->julia->constant_b += 0.01;
		if (keycode == 65364)
			window->julia->constant_b -= 0.01;
		if (keycode == 65361)
			window->julia->constant_a += 0.01;
		if (keycode == 65363)
			window->julia->constant_a -= 0.01;
		julia_calculation(window);
		update_image_display(window);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_win *window)
{
	
	if (button == 4)
		window->zoom *= 1.1;
	if (button == 5)
		window->zoom /= 1.1;
	if (window->option == 0)
		mandelbro_calculation(window);
	if (window->option == 1)
		julia_calculation(window);
	(void)x;
	(void)y;
	update_image_display(window);
	return (0);
}
