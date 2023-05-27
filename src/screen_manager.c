/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:25:51 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/27 19:04:03 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_image_display(t_win *main)
{
	mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->canva->img_ptr,
		main->image_x, main->image_y);
}

void	place_pixel(t_win *main, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < main->canva->w && y < main->canva->h)
	{
		dst = main->canva->addr + (y * main->canva->line_len + x
				* (main->canva->bit_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

t_img	*new_img(int w, int h, t_win *window)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (!image)
		return (NULL);
	image->win = window;
	image->w = w;
	image->h = h;
	image->img_ptr = mlx_new_image(window->mlx_ptr, w, h);
	image->addr = mlx_get_data_addr(image->img_ptr, &(image->bit_per_pixel),
			&(image->line_len), &(image->endian));
	image->x = 20;
	image->y = 20;
	return (image);
}

void	create_window(t_win *main, char *name)
{
	main->mlx_ptr = mlx_init();
	main->win_ptr = mlx_new_window(main->mlx_ptr, main->width, main->height,
			name);
}
