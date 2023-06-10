/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/10 11:03:08 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	const real can go from -2 to 2
	const imaginary can go from -2 to 2
	screen->n is the number of iterations
	ANGLE for the angle of the leaf
*/
float	tricorn(float const_r, float const_i, t_win *screen)
{
	float		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = const_r;
	zi = const_i;
	n = 0;
	while (n < screen->n)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = -2 * zr * zi + const_i;
		zr = zr * zr - zi * zi + const_r;
		zi = tmp;
		n++;
	}
	return (n);
}
