/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:35:24 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/09 13:16:53 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	clean_imgs(t_win *canvas)
{
	if (!canvas->canva)
		return ;
	if (canvas->canva->img_ptr)
		mlx_destroy_image(canvas->mlx_ptr, canvas->canva->img_ptr);
	free(canvas->canva);
}

static void	clean_screen(t_win *ptr)
{
	if (!ptr)
		return ;
	if (ptr->win_ptr)
		mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	if (ptr->mlx_ptr)
		mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
}

void	close_program(t_win *screen, char *msg, int status)
{
	clean_imgs(screen);
	clean_screen(screen);

	if (status == 2)
		ft_printf("%s%s%s\n", BRED, msg, RESET);
	if (status == 1)
		ft_printf("%s%s\n%s", BHGRN, msg, RESET);
	exit(status);
}