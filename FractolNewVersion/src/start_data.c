/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/06 00:29:35 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	~ Initialize Data function:
		~ Initialize all data to 0 or NULL
*/
void	start_data_preset(t_fractal *all)
{
	all->mlx = NULL;
	all->win = NULL;
	all->img = NULL;
	all->addr = NULL;
	all->bpp = 0;
	all->line_len = 0;
	all->endian = 0;
	all->type = 0;
	all->min_r = 0;
	all->max_r = 0;
	all->min_i = 0;
	all->max_i = 0;
	all->kr = 0;
	all->ki = 0;
	all->sx = 1;
	all->rx = 0;
	all->fx = 0;
	all->palete = NULL;
	all->color_pattern = 2;
} 
