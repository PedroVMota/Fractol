/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/25 15:44:46 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	initialize_data(t_win *screen, int fractal)
{
	screen->height = HEIGHT;
	screen->width = WIDTH;
	screen->mlx_ptr = NULL;
	screen->win_ptr = NULL;
	screen->image_x = 0;
	screen->image_y = 0;
	screen->offset_x = 1;
	screen->offset_y = 1;
	screen->interactions = 150;
	screen->zoom = 1;
	screen->option = fractal;
	if (fractal == 0)
	{
		screen->mandelbrot = malloc(sizeof(t_mandelbrot));
		if (!screen->mandelbrot)
			return (2);
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
			return (2);
		screen->julia->ratio_x = 0;
		screen->julia->ratio_y = 0;
		screen->julia->real_part = 0;
		screen->julia->imaginary_part = 0;
		screen->julia->constant_a = -0.8;
		screen->julia->constant_b = 0.156;
	}
	return (0);
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
		printf("Mouse X %d\n", screen->mouse_x);
		printf("Mouse Y %d\n", screen->mouse_y);
		printf("Image X %d\n", screen->image_x);
		printf("Image Y %d\n", screen->image_y);
		printf("Offset X %f\n", screen->offset_x);
		printf("Offset Y %f\n", screen->offset_y);
		printf("Zoom %f\n", screen->zoom);
		printf("Option %s\n", (screen->option == 0) ? "Mandelbrot" : "Julia");
		if (screen->mandelbrot)
		{
			printf("Mandelbrot ratio X %f\n", screen->mandelbrot->ratio_x);
			printf("Mandelbrot ratio Y %f\n", screen->mandelbrot->ratio_y);
		}
		if (screen->julia)
		{
			printf("julia ratio X %f\n", screen->julia->ratio_x);
			printf("julia ratio Y %f\n", screen->julia->ratio_y);
		}
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