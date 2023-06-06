/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:19:55 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/01 16:25:51 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void close_and_clean(int exit_status, char *msg, t_fractal *all)
{
	if(all->img)
		mlx_destroy_image(all->mlx, all->img);
	if(all->win && all->mlx)
		mlx_destroy_window(all->mlx, all->win);
	if(all->mlx)
	{
		/*mlx_destroy_display(all->mlx);*/
		free(all->mlx);
	}
	ft_printf("%s\n", msg);
	exit(exit_status);
}