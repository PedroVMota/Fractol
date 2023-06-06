/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:33:24 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/01 16:26:35 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	~ Set Data Fractal:
	~ Maps the complex number axes to the window width and height to
		~ create an equivalence between a given pixel and a complex number.
	
*/
void set_data_fractal(t_fractal *all)
{
	if(all->type == JULIA)
	{
		all->min_i = -4;
		all->max_i = 4;
		all->min_r = -4;
		all->max_i = all->min_i + (all->max_r - all->min_r) * HEIGHT / WIDTH;
	}
	else{
		all->min_i = -2;
		all->max_i = 2;
		all->min_r = -2;
		all->max_i = all->min_i + (all->max_r - all->min_r) * HEIGHT / WIDTH;
	}
}


