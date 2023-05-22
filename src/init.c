/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/22 20:34:33 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_win	*screen(void)
{
	static t_win screen;

	screen.height = HEIGHT;
	screen.width = WIDTH;
	screen.ratio = malloc(sizeof(t_map));
	if (!screen.ratio)
		return (NULL);
	screen.ratio->x_end = 2;
	screen.ratio->x_start = -2;
	screen.ratio->y_end = 2;
	screen.ratio->y_start = -2;
	screen.formula = malloc(sizeof(t_complex));
	if (!screen.formula)
		return (NULL);
	screen.formula->imaginary = 0;
	screen.formula->real = 0;
	return (&screen);
}