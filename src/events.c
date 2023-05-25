/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/25 15:43:50 by pvital-m         ###   ########.fr       */
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
	mlx_clear_window(screen->mlx_ptr, screen->win_ptr);
	if (screen->image_x + 250 > 1000)
		return ;
	(screen->image_x += 250);
	if (screen->option == 0)
		mandelbro_calculation(screen, 300);
	if (screen->option == 1)
		julia_calculation(screen, 300);
}
void	move_left(t_win *screen)
{
	mlx_clear_window(screen->mlx_ptr, screen->win_ptr);
	if (screen->image_x - 250 < -1000)
		return ;
	(screen->image_x -= 250);
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
	system("clear");
	update_image_display(window);
	return (0);
}
int	mouse_hook(int button, int x, int y, t_win *window)

{
	printf("Mouse button pressed %d\n", button);
	if (button == 4)
	{
		window->zoom *= 1.1;
		window->mouse_x = x;
		window->mouse_y = y;
	}
	if (button == 5)
	{
		window->zoom /= 1.1;
		window->mouse_x = x;
		window->mouse_y = y;
	}
	if (window->option == 0)
		mandelbro_calculation(window, 300);
	if (window->option == 1)
		julia_calculation(window, 300);
	update_image_display(window);
	print_data(window);
	return (0);
}