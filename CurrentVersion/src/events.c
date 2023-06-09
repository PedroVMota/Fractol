/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:10:01 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/08 14:07:57 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_win *window)
{
	// printf("keycode: %d\n", keycode);
	if (keycode == 53)
		close_program(window);
	if (keycode == 126)
		window->ci += 0.005;
	if (keycode == 125)
		window->ci -= 0.005;
	if (keycode == 124)
		window->cr += 0.005;
	if (keycode == 123)
		window->cr -= 0.005;
	build(window);
	(void)window;
	return (0);
}

int	mouse_hook(int button, int x, int y, t_win *window)
{
	// printf("button: %d\n", button);
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
