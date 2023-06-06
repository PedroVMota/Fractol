/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:35:24 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/01 23:15:00 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	New Image function:
	-> Allocates memory for the MLX image and its buffer.
	-> Allocates memory for the color palette.
*/
void	new_img(t_fractal *all)
{
	int bbp;
	int line_len;
	int endian;
	char *buf;
	
	all->palete = ft_calloc(sizeof(t_fractal), MAX_INTERACTIONS);
	if(!all->palete)
		close_and_clean(2, "Palette allocation failed", all);
	all->img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	if(!all->img)
		close_and_clean(2, "Image allocation failed", all);
	printf(">>>> %p\n\n", all->addr);
	all->addr = mlx_get_data_addr(all->img, &bbp, &line_len, &endian);
	if(!all->addr)
		close_and_clean(2, "Image buffer allocation failed", all);
}

/*
	Reset Image Function:
	-> Cleanly reinitializes the MLX image if the color palette or 
	-> Fractal type is modified at runtime.
*/
void	reset_img(t_fractal *all)
{
	if (all->mlx && all->img)
		mlx_destroy_image(all->mlx, all->img);
	if (all->palete)
		free(all->palete);
	if (all->addr)
		all->addr = NULL;
	new_img(all);
}
