/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:57:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/10 08:21:51 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_percent(int color, double percent)
{
	int		rgb[3];
	int		trgb[3];
	double	percentage;

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	percentage = (percent / 100) * 256;
	trgb[0] = (rgb[0] + percentage) - 256;
	trgb[1] = (rgb[1] + percentage) - 256;
	trgb[2] = (rgb[2] + percentage) - 256;
	return (0xFF << 24 | trgb[0] << 16 | trgb[1] << 8 | trgb[2]);
}

int	mix_colors(int start, int final, int percent)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((start >> 16) & 0xFF);
	start_rgb[1] = ((start >> 8) & 0xFF);
	start_rgb[2] = ((start >> 0) & 0xFF);
	end_rgb[0] = ((final >> 16) & 0xFF);
	end_rgb[1] = ((final >> 8) & 0xFF);
	end_rgb[2] = ((final >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * percent + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * percent + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * percent + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}
