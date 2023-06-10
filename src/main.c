/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:33:23 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/10 11:55:07 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	finish(t_win *screen)
{
	close_program(screen, "Software Closed!", 1);
	return (1);
}

int	ft_render_frame(t_win *screen)
{
	build(screen);
	mlx_key_hook(screen->win_ptr, key_hook, screen);
	mlx_mouse_hook(screen->win_ptr, mouse_hook, screen);
	mlx_hook(screen->win_ptr, 17, 1L << 17, finish, screen);
	mlx_loop(screen->mlx_ptr);
	return (0);
}

int	window_init(void)
{
	create_window(screen(), "fract-ol");
	if (!screen()->win_ptr)
		return (2);
	(screen())->canva = new_img(WIDTH, HEIGHT, screen());
	ft_render_frame(screen());
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		print_help_screen();
	config_all(av, ac);
	window_init();
	return (0);
}
