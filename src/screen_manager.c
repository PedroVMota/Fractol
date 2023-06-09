/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:25:51 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/09 18:17:44 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_image_display(t_win *main)
{
	if (!main->canva)
		close_program(main, "There is no pointer to canva", 2);
	mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->canva->img_ptr, \
			0, 0);
}

void	place_pixel(t_win *main, int x, int y, int color)
{
	char	*dst;

	if (!main->canva)
		close_program(main, "There is no pointer to canva", 2);
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = main->canva->addr + (y * main->canva->line_len + x
				* (main->canva->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

t_img	*new_img(int w, int h, t_win *window)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (!image)
		return (NULL);
	image->img_ptr = mlx_new_image(window->mlx_ptr, w, h);
	if (!image->img_ptr)
		close_program(window, "Creating Image Error", 2);
	image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp),
			&(image->line_len), &(image->endian));
	if (!image->addr)
		close_program(window, "Creating Image Error", 2);
	return (image);
}

void	create_window(t_win *main, char *name)
{
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		close_program(main, "Creating Window Error", 2);
	main->win_ptr = mlx_new_window(main->mlx_ptr, WIDTH, HEIGHT, name);
	if (!main->win_ptr)
		close_program(main, "Creating Window Error", 2);
}
