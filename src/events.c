/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:10:01 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/10 12:19:42 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	switch_color(void)
{
	if (screen()->pallete + 1 < 4)
		screen()->pallete += 1;
	else
		screen()->pallete = 1;
	build(screen());
}

static void	modified_number(float *n, float increament)
{
	*n += increament;
	build(screen());
}

int	key_hook(int keycode, t_win *window)
{
	if (keycode == 53 || keycode == 65307)
		close_program(window, "The program closed with success", 1);
	else if (keycode == 126 || keycode == 65364)
		modified_number(&window->ci, 0.005);
	else if (keycode == 125 || keycode == 65362)
		modified_number(&window->ci, -0.005);
	else if (keycode == 124 || keycode == 65361)
		modified_number(&window->cr, 0.005);
	else if (keycode == 123 || keycode == 65363)
		modified_number(&window->cr, -0.005);
	else if (keycode == 119)
		modified_number(&window->mouse->offset_y, -SHIFT_AMOUNT);
	else if (keycode == 115)
		modified_number(&window->mouse->offset_y, SHIFT_AMOUNT);
	else if (keycode == 97 || keycode == 0)
		modified_number(&window->mouse->offset_x, -SHIFT_AMOUNT);
	else if (keycode == 100 || keycode == 2)
		modified_number(&window->mouse->offset_x, SHIFT_AMOUNT);
	else if (keycode == 65451 || keycode == 24)
		window->n += 10;
	else if (keycode == 65453 || keycode == 44)
		window->n -= 10;
	else if (keycode == 32 || keycode == 49)
		switch_color();
	printf("Key: %i\n", keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_win *window)
{
	window->mouse->offset_x = (x - (WIDTH / 2)) * 0.1;
	window->mouse->offset_y = (y - (HEIGHT / 2)) * 0.1;
	if (button == 4)
	{
		window->mouse->mouse_x *= 1.1;
		window->mouse->mouse_y *= 1.1;
		window->mouse->mouse_x += window->mouse->offset_x;
		window->mouse->mouse_y += window->mouse->offset_y;
		window->zoom *= 1.1;
	}
	if (button == 5)
	{
		window->mouse->mouse_x /= 1.1;
		window->mouse->mouse_y /= 1.1;
		window->mouse->mouse_x -= window->mouse->offset_x;
		window->mouse->mouse_y -= window->mouse->offset_y;
		window->zoom /= 1.1;
	}
	build(window);
	return (0);
}
