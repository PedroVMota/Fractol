/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:33:23 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/24 15:42:10 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_render_frame(t_win *main)
{
	int	inte;

	print_data(screen());
	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < HEIGHT; y++)
		{
			inte = ft_fractal_mandelbrot(screen(), 500, x, y);
			if (inte == 500)
				place_pixel(main, x, y, gen_trgb(0, 255, 255, 255));
			else
				place_pixel(main, x, y, gen_trgb(0, 0, 0, 0));
		}
	mlx_hook(main->win_ptr, 2, 1L << 0, key_hook, main);
	update_image_display(main);
	mlx_loop(main->mlx_ptr);
	return (0);
}

int	window_init(void)
{
	int	return_value;

	initialize_data(screen());
	create_window(screen(), "fract-ol");
	if (!screen()->win_ptr)
		return (2);
	screen()->canva = new_img(WIDTH, HEIGHT, screen());
	ft_render_frame(screen());
	return (return_value);
}

int	main(int ac, char **av)
{
	int	status;

	system("clear");
	status = 0;
	if (ac == 1)
		status = print_help_screen();
	if (ac == 2)
	{
		if (ft_check_paramters(av[1]))
			status = window_init();
		else
			status = print_help_screen();
	}
	return (0);
}
