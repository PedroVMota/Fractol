/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:33:24 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/09 21:10:32 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(float cr, float ci, t_win *screen)
{
	float	zr;
	float	zi;
	int		i;
	float	tmp;

	zr = 0;
	zi = 0;
	i = 0;
	(void)screen;
	while (i < screen->n)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		i++;
	}
	return (i);
}
