/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zebra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:21:44 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/01 22:14:25 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void black_and_white(t_fractal *all, int color)
{
	int	color2;

	color2 = convert_color_to_percent(color, 50);
	fill_color(all, color, 1);
	fill_color(all, color2, 2);
	all->palete[MAX_INTERACTIONS - 1] = 0;
}