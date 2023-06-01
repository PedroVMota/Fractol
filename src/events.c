/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:11:00 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/31 21:14:14 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int	key_hook(int keycode, t_win *window)
{
	// printf("Interactions: %d\n", window->interactions);
	interactions_events(keycode, window);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_win *window)
{
	printf("\n");
	if(button == 5)
		zoom_in(x, y);
	if(button == 4)
		zoom_out(x, y);	
	fracta_builder(window);
	update_image_display(window);
	return (0);
}