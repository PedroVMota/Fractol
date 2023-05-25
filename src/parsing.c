/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 08:51:07 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/20 16:33:19 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	ft_check_paramters(char *arg)
{
	if (arg[0] == 'j')
		return (true);
	else if (arg[0] == 'm')
		return (true);
	return (false);
}

int	print_help_screen(void)
{
	ft_printf("=========== HELP SCREEN ===========\n");
	ft_printf("Usage: ./fractol [fractal]\n");
	ft_printf("[m] >>> Mandelbrot\n");
	ft_printf("[j] >>> Julia\n");
	ft_printf("=========== HELP SCREEN ===========\n");
	return (2);
}
