/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:33:24 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/06 00:08:04 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	mandelbrot(int cr, int ci)
{
	int	zr;
	int	zi;
	int	i;
	int	tmp;

	zr = 0;
	zi = 0;
	i = 0;
	while (i < MAX_INTERACTIONS)
	{
		if (zr * zr + zi * zi > 4)
			break ;
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}