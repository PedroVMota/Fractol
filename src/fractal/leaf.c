/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/09 18:16:48 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	const real can go from -2 to 2
	const imaginary can go from -2 to 2
	screen->n is the number of iterations
	ANGLE for the angle of the leaf
*/
int	leaf(float const_r, float const_i, t_win *screen)
{
	double	x;
	double	y;
	int		i;
	double	x_new;
	double	y_new;

	x = 0.0;
	y = 0.0;
	i = 0;
	while (i < screen->n)
	{
		x_new = sin(ANGLE * y) + const_r;
		y_new = sin(ANGLE * x) + const_i;
		x = x_new;
		y = y_new;
		if (x * x + y * y > 4.0 * 4.0)
			return (i);
	}
	return (screen->n);
}
