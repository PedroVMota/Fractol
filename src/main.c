/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:33:23 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/24 22:37:25 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_render_frame(t_win *main, int option)
{
	int	inte;

	if (option == 0)
		mandelbro_calculation(main, 300);
	if (option == 1)
		julia_calculation(main, 300);
	mlx_hook(main->win_ptr, 2, 1L << 0, key_hook, main);
	update_image_display(main);
	mlx_loop(main->mlx_ptr);
	return (0);
}

int	window_init(int options)
{
	int	return_value;

	initialize_data(screen());
	create_window(screen(), "fract-ol");
	if (!screen()->win_ptr)
		return (2);
	screen()->canva = new_img(WIDTH, HEIGHT, screen());
	ft_render_frame(screen(), options);
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
		{
			if (av[1][0] == 'm')
				status = window_init(0);
			else if (av[1][0] == 'j')
				status = window_init(1);
			else
				status = print_help_screen();
		}
		else
			status = print_help_screen();
	}
	return (0);
}
