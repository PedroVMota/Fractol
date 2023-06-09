/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:27:19 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/10 11:09:22 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	julia(t_win *screen, double zr, double zi)
{
	float	n;
	double	tmp;

	n = 0;
	while (n < screen->n)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + screen->ci;
		zr = zr * zr - zi * zi + screen->cr;
		zi = tmp;
		n++;
	}
	return (n);
}
