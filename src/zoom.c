/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:23:59 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/31 21:12:48 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void zoom_in(int x, int y)
{
	screen()->zoom *= 1.1;
	screen()->ratio_x = (x - (WIDTH / 2)) * screen()->zoom;
	screen()->ratio_y = (y - (HEIGHT / 2)) * screen()->zoom;
	screen()->real_part += screen()->ratio_x;
	screen()->imaginary_part += screen()->ratio_y;
	screen()->mouse_x = x;
	screen()->mouse_y = y;
}
void zoom_out(int x, int y)
{
	screen()->zoom /= 1.1;
	screen()->ratio_x = (x - (WIDTH / 2)) * screen()->zoom;
	screen()->ratio_y = (y - (HEIGHT / 2)) * screen()->zoom;
	screen()->mouse_x = x;
	screen()->mouse_y = y;
	screen()->real_part += screen()->ratio_x;
	screen()->imaginary_part += screen()->ratio_y;
}
void zoom_reset(void)
{
	screen()->zoom = 1;
	screen()->ratio_x = 0;
	screen()->ratio_y = 0;
	screen()->real_part = 0;
	screen()->imaginary_part = 0;
}