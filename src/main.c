/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:33:23 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/22 20:24:56 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_render_frame(t_win *main)
{
	place_pixel(main, main->canva->x, main->canva->y, gen_trgb(0, 255, 0, 0));
	mlx_hook(main->win_ptr, 2, 1L << 0, key_hook, main);
	update_image_display(main);
	mlx_loop(main->mlx_ptr);
	return (0);
}

int	window_init(void)
{
	t_img		img;
	t_complex	formula;
	int			return_value;

	create_window(screen(), "fract-ol");
	if (!screen()->win_ptr)
		return (2);
	img = new_img(WIDTH, HEIGHT, screen());
	ft_fractal_mandelbrot(screen(), 300);
	screen()->canva = &img;
	return_value = ft_render_frame(screen());
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
