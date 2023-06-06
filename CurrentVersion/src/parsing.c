/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 08:51:07 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/06 00:33:58 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void set_lower_case(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}
static void set_type_of_fractol(char *fractol)
{
	set_lower_case(fractol);
	if (ft_strncmp(fractol, "mandelbrot", ft_strlen("mandelbrot")+1) == 0 || ft_strncmp(fractol, "m", 2) == 0)
		screen()->set = MANDELBROT;
	else if (ft_strncmp(fractol, "julia", ft_strlen("julia")+1) == 0 || ft_strncmp(fractol, "j", 2) == 0)
		screen()->set = JULIA;
	else
		print_help_screen();
}
void config_all(char **av)
{
	set_type_of_fractol(av[1]);
	initialize_data(screen());
	if(screen()->set != JULIA)
	{
		screen()->constant_real = 0;
		screen()->constant_imaginary = 0;
		return ;
	}
	screen()->constant_real = -0.8;
	screen()->constant_imaginary = 0.156;
}

void	print_help_screen(void)
{
	ft_printf("=========== HELP SCREEN ===========\n");
	ft_printf("Usage: ./fractol [fractal]\n");
	ft_printf("[m] >>> Mandelbrot\n");
	ft_printf("[j] >>> Julia\n");
	ft_printf("=========== HELP SCREEN ===========\n");
	exit(2);
}
