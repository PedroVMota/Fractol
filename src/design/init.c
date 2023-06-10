/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:05:26 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/10 09:54:23 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void	create_graph(t_win *screen, float interactions, int x, int y)
{
	if (screen->pallete == ZEBRA)
		zebra_pallete(screen, interactions, x, y);
	if (screen->pallete == RAINBOW)
		rainbow_palette(screen, interactions, x, y);
	if (screen->pallete == MONO_COLOR)
		color_shift(interactions, x, y, 6);
	return ;
}
