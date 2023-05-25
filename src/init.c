/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/25 09:07:45 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_data(t_win *screen, int fractal)
{
	screen->height = HEIGHT;
	screen->width = WIDTH;
	screen->mlx_ptr = NULL;
	screen->win_ptr = NULL;
	if (fractal == 0)
	{
		screen->mandelbrot = malloc(sizeof(t_mandelbrot));
		if (!screen->mandelbrot)
			return ;
		screen->mandelbrot->ratio_x = 0;
		screen->mandelbrot->ratio_y = 0;
		screen->mandelbrot->real_part = 0;
		screen->mandelbrot->imaginary_part = 0;
		screen->mandelbrot->constant_b = 0;
		screen->mandelbrot->constant_b = 0;
	}
	else if (fractal == 1)
	{
		screen->julia = malloc(sizeof(t_julia));
		if (!screen->julia)
			return ;
		screen->julia->ratio_x = 0;
		screen->julia->ratio_y = 0;
		screen->julia->real_part = 0;
		screen->julia->imaginary_part = 0;
		screen->julia->constant_a = -0.8;
		screen->julia->constant_b = 0.156;
	}
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
				GRNB,
				RESET);
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
				GRNB,
				RESET);
	}
}

t_win	*screen(void)
{
	static t_win screen;
	return (&screen);
}