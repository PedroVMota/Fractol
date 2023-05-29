/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:35:24 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/29 11:00:52 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_program(t_win *screen)
{
	mlx_destroy_image(screen->mlx_ptr, screen->canva->img_ptr);
	mlx_destroy_window(screen->mlx_ptr, screen->win_ptr);
	ft_printf("%sProgram closed with success\n%s", BHGRN, RESET);
	exit(1);
}
