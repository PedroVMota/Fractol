/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/23 17:18:08 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_data(t_win *screen)
{
	screen->height = HEIGHT;
	screen->width = WIDTH;
	screen->ratio = malloc(sizeof(t_map));
	if (!screen->ratio)
	{
		return ;
	}
	screen->ratio->x_end = 2;
	screen->ratio->x_start = -2;
	screen->ratio->y_end = 2;
	screen->ratio->y_start = -2;
	screen->formula = malloc(sizeof(t_complex));
	if (!screen->formula)
	{
		free(screen->ratio);
		return ;
	}
	screen->formula->imaginary = 0;
	screen->formula->real = 0;
}

void	print_data(t_win *screen)
{
	if (screen)
	{
		printf("%s============ DATA ============\n%s", YEL, RESET);
		printf("Win Address: %p\n", screen);
		printf("Screen Height: %i\n", screen->height);
		printf("Screen Width: %i\n", screen->width);
		printf("Screen mlx pinter: %p\n", screen->mlx_ptr);
		printf("Screen win pinter: %p\n", screen->win_ptr);
		printf("%s============ DATA ============%s\n", YEL, RESET);
		printf("%s==================================================%s\n",
				GRNB, RESET);
	}
	if (screen->canva)
	{
		printf("%s============ CANVA ============\n%s", YEL, RESET);
		printf("Canva Address: %p\n", screen->canva);
		printf("Canva Height: %i\n", screen->canva->h);
		printf("Canva Width: %i\n", screen->canva->w);
		printf("Canva Pixel Address: %p\n", screen->canva->addr);
		printf("Canva Pixel Bits per pixel: %i\n",
				screen->canva->bit_per_pixel);
		printf("Canva Pixel Line length: %i\n", screen->canva->line_len);
		printf("Canva Pixel Endian: %i\n", screen->canva->endian);
		printf("%s============ CANVA ============%s\n", YEL, RESET);
		printf("%s==================================================%s\n",
				GRNB, RESET);
	}
	if (screen->formula)
	{
		printf("%s============ FORMULA ============%s\n", YEL, RESET);
		printf("Formula Address: %p\n", screen->formula);
		printf("Formula Real: %f\n", screen->formula->real);
		printf("Formula Imaginary: %f\n", screen->formula->imaginary);
		printf("%s============ FORMULA ============%s\n", YEL, RESET);
		printf("%s==================================================%s\n",
				GRNB, RESET);
	}
	if (screen->ratio)
	{
		printf("%s============ RATIO ============%s\n", YEL, RESET);
		printf("Ratio Address: %p\n", screen->ratio);
		printf("Ratio X Start: %f\n", screen->ratio->x_start);
		printf("Ratio X End: %f\n", screen->ratio->x_end);
		printf("Ratio Y Start: %f\n", screen->ratio->y_start);
		printf("Ratio Y End: %f\n", screen->ratio->y_end);
		printf("%s============ RATIO ============%s\n", YEL, RESET);
		printf("%s==================================================%s\n",
				GRNB, RESET);
	}
}

t_win	*screen(void)
{
	static t_win screen;
	return (&screen);
}