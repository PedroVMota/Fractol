/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:10:01 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/09 11:47:42 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_win *window)
{
	printf("Keyboard: keycode: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		close_program(window);
	if (keycode == 126 || keycode == 65364)
		window->ci += 0.1;
	if (keycode == 125 || keycode == 65362)
		window->ci -= 0.1;
	if (keycode == 124 || keycode == 65361)
		window->cr += 0.1;
	if (keycode == 123 || keycode == 65363)
		window->cr -= 0.1;
	if(keycode == 32)
		system("clear");
	build(window);
	(void)window;
	return (0);
}

int	mouse_hook(int button, int x, int y, t_win *window)
{
	printf("Mouse: button: %d\n", button);
	if (button == 5)
		window->zoom *= 1.1;
	if (button == 4)
			window->zoom /= 1.1;
	build(window);
	(void)button;
	(void)window;
	(void)x;
	(void)y;
	return (0);
}


