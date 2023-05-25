/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/25 13:26:14 by pvital-m         ###   ########.fr       */
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

void	mandelbro_calculation(t_win *screen, int max)
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
			inte = ft_fractal_mandelbrot(screen, max, x, y);
			color_palette(screen, inte, x, y);
			y++;
		}
		x++;
	}
}

void	julia_calculation(t_win *screen, int max)
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
			inte = ft_fractal_julia(screen, max, x, y);
			color_palette(screen, inte, x, y);
			y++;
		}
		x++;
	}
}

void	move_right(t_win *screen)
{
	if (screen->image_x + 0.5 > 1000)
		return ;
	(screen->image_x += 0.5);
	if (screen->option == 0)
		mandelbro_calculation(screen, 300);
	if (screen->option == 1)
		julia_calculation(screen, 300);
}
void	move_left(t_win *screen)
{
	if (screen->image_x - 50 < -1000)
		return ;
	(screen->image_x -= 50);
	if (screen->option == 0)
		mandelbro_calculation(screen, 300);
	if (screen->option == 1)
		julia_calculation(screen, 300);
}

int	key_hook(int keycode, t_win *window)
{
	if (keycode == ESC || keycode == 65307)
		close_program(window);
	if (keycode == 65363)
		move_right(window);
	if (keycode == 65361)
		move_left(window);
	update_image_display(window);
	printf("Image Updated!\n");
	return (0);
}