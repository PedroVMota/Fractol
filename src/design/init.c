/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/09 18:17:21 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mono_cromatic(t_win *screen, int n, int x, int y)
{
	int		red;
	int		green;
	int		blue;
	double	t;
	int		color;

	red = 0;
	green = 0;
	blue = 0;
	if (n < screen->n)
	{
		if (n < screen->n)
		{
			t = (double)n / screen->n;
			red = ((screen->color >> 16) & 0xFF) * t + ((0 >> 16) & 0xFF) * (1 \
				- t);
			green = ((screen->color >> 8) & 0xFF) * t + ((0 >> 8) & 0xFF) * (1 \
				- t);
			blue = (screen->color & 0xFF) * t + (0 & 0xFF) * (1 - t);
		}
	}
	color = (red << 16) | (green << 8) | blue;
	place_pixel(screen, x, y, color);
}

void	create_graph(t_win *screen, int interactions, int x, int y)
{
	if (screen->pallete == ZEBRA)
		zebra_pallete(screen, interactions, x, y);
	if (screen->pallete == RAINBOW)
		rainbow_palette(screen, interactions, x, y);
	if (screen->pallete == MONO_COLOR)
		mono_cromatic(screen, interactions, x, y);
	return ;
}
