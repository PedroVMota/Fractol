/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:33:24 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/29 11:46:28 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fracta_builder(t_win *screen)
{
	int	inte;
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (screen->option == 0)
		printf("MandelBrot\n");
	if (screen->option == 0)
		printf("Julia\n");
	if (screen->color_mode == BLACK_AND_WIRTE)
		printf("BLACK WHITE\n");
	if (screen->option == COLORFULL)
		printf("COLORFULL\n");
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (screen->option == 0)
				inte = ft_fractal_mandelbrot(screen, x, y);
			if (screen->option == 1)
				inte = ft_fractal_julia(screen, x, y);
			if (screen->color_mode == BLACK_AND_WIRTE)
				zebra_pallete(screen, inte, x, y);
			if (screen->color_mode == COLORFULL)
				default_pallete(screen, inte, x, y);
			y++;
		}
		x++;
	}
}
