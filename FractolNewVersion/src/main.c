/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:59 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/01 23:15:11 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	~ main function:
	~ Check if all aguments are valid, if not, print help screen.
	~ Validate arguments:
	~ 	-> Check if the argument is a valid fractal name.
	~ 	-> real and imaginary part of the complex number for julia. must be two
	~ 		values otherwise will be considered as invalid. And is converted to
	~ 		interactions; 

*/

void _show_data(t_fractal *all)
{
	printf("%sStruct Information%s\n", YEL, RESET);
	printf("mlx: %p\n", all->mlx);
	printf("Win: %p\n", all->win);
	printf("Img: %p\n", all->img);
	printf("Addr: %p\n", all->addr);
	printf("Palete: %p\n", all->palete);
	printf("Bpp: %i\n", all->bpp);
	printf("Length Line: %i\n", all->line_len);
	printf("Endian: %i\n", all->endian);
}

/*
	Start Function:
	~ Initialize mlx and window.
	~ Set default values for the fractal.
	~ Set default values for the complex number.
		sx: Scale X: 2.0
			-> The scale is the size of the fractal in the screen.
		rx: Real X: 0.5
			-> The real part of the complex number.
		fx: Factor X: 1.0
			-> The factor is the number of interactions.
*/
void start(t_fractal *all)
{
	all->mlx = mlx_init();
	if(!all->mlx)
		close_and_clean(2, "Mlx init failed", all);
	all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, "Fractol");
	if(!all->win)
		close_and_clean(2, "Window init failed", all);
	new_img(all);
	all->sx = 2.0;
	all->rx = 0.5;
	all->fx = 1.0;
	set_data_fractal(all);
}

int	main(int ac, char **av)
{
	t_fractal all;

	if (ac == 1)
		print_help_screen();
	start_data_preset(&all);
	set_args(av, ac, &all);
	start(&all);
	render(&all);
	mlx_loop(all.mlx);
}
