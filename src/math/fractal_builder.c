/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:33:24 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/27 17:33:45 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbro_calculation(t_win *screen)
{
	int	inte;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			inte = ft_fractal_mandelbrot(screen, x, y);
			color_palette(screen, inte, x, y);
			y++;
		}
		x++;
	}
}

void	julia_calculation(t_win *screen)
{
	int	inte;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT + 500)
		{
			inte = ft_fractal_julia(screen, x, y);
			color_palette(screen, inte, x, y);
			y++;
		}
		x++;
	}
}
