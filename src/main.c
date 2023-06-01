/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:33:23 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/31 21:14:06 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_render_frame(t_win *main)
{
	fracta_builder(main);
	mlx_hook(main->win_ptr, 2L, 1L << 0, key_hook, main);
	mlx_mouse_hook(main->win_ptr, mouse_hook, main);
	update_image_display(main);
	mlx_loop(main->mlx_ptr);
	return (0);
}

int	window_init()
{
	initialize_data(screen());
	create_window(screen(), "fract-ol");
	if (!screen()->win_ptr)
		return (2);
	screen()->canva = new_img(WIDTH, HEIGHT, screen());
	if(!screen()->canva)
		return (2);
	ft_render_frame(screen());
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		print_help_screen();
	validate_arguments(&av[1]);
	if (window_init() == 2)
		return (2);
}
