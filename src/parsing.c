/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 08:51:07 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/09 14:08:59 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_lower_case(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}
static void	set_type_of_fractol(char *fractol)
{
	set_lower_case(fractol);
	if (ft_strncmp(fractol, "mandelbrot", ft_strlen("mandelbrot") + 1) == 0
		|| ft_strncmp(fractol, "m", 2) == 0)
		screen()->set = MANDELBROT;
	else if (ft_strncmp(fractol, "julia", ft_strlen("julia") + 1) == 0
			|| ft_strncmp(fractol, "j", 2) == 0)
		screen()->set = JULIA;
	else
		print_help_screen();
}
void	config_all(char **av, int ac)
{
	set_type_of_fractol(av[1]);
	initialize_data(screen());
	if (screen()->set == MANDELBROT && ac == 2)
	{
		screen()->cr = 0;
		screen()->ci = 0;
		return ;
	}
	else if (screen()->set == JULIA && ac == 4)
	{
		screen()->cr = ft_atof(av[2]);
		screen()->ci = ft_atof(av[3]);
	}
	else
		print_help_screen();
}

void	print_help_screen(void)
{
	printf("=========== HELP SCREEN ===========\n");
	printf("Usage of Fractol:\n");
	printf("    Mandelbrot: ./fractol {Mandelbrot || m} {color}\n");
	printf("    Julia: ./fractol {Julia || j} {Real} {Imaginary} {color}\n");
	printf("===================================\n");
	close_program(screen(), "Program was not executed correctly", 2);
}
