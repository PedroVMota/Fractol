/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zebra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:04:09 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/08 12:21:05 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_even(int n)
{
	if (n % 2 == 0)
		return (1);
	return (0);
}

static int	rgb(int t, int r, int g, int b)
{
	int	color;

	color = t << 24 | r << 16 | g << 8 | b;
	if (color < 0)
		color = -color;
	return (color);
}

void	zebra_pallete(t_win *main, int inte, int x, int y)
{
	if (is_even(inte))
		place_pixel(main, x, y, rgb(0, 0, 0, 0));
	else
		place_pixel(main, x, y, rgb(0, 255, 255, 255));
}
