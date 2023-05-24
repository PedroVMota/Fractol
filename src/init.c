/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital@student.42lisbon.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:20:30 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/24 23:32:17 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_data(t_win *screen, char *n)
{
	screen->interactions = ft_atoi(n);
	screen->height = HEIGHT;
	screen->width = WIDTH;
	screen->mlx_ptr = NULL;
	screen->win_ptr = NULL;
	
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