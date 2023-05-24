/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital@student.42lisbon.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 08:51:07 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/24 23:34:36 by pvital-m         ###   ########.fr       */
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

bool	interaction_validation(char *n)
{
	if (*n == '0' || !n || !*n)
		return true;
	return false;
}

int	print_help_screen(void)
{
	ft_printf("=========== HELP SCREEN ===========\n");
	ft_printf("Usage: ./fractol [ fractal ] [ Nº of interaction ]\n");
	ft_printf("[m] >>> Mandelbrot\n");
	ft_printf("[j] >>> Julia\n");
	ft_printf("=========== HELP SCREEN ===========\n");
	return (2);
}
