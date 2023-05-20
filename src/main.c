/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:33:23 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/20 17:34:01 by pvital-m         ###   ########.fr       */
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
	int		return_value;
	t_win	tutorial;
	t_img	img;
	tutorial = create_window(300, 300, "fract-ol");
	if (!tutorial.win_ptr)
		return (2);
	img = new_img(300, 300, &tutorial);
	tutorial.canva = &img;
	return_value = ft_render_frame(&tutorial);
	return (return_value);
}

int	main(int ac, char **av)
{
	int	status;

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
