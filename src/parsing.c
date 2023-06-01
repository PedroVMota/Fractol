/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 08:51:07 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/29 17:29:08 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_string_to_lower(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

static int	set_type(char *arg)
{
	if (!arg)
		return (0);
	set_string_to_lower(arg);
	if ((!ft_strncmp(arg, "julia", ft_strlen(arg) + 1) ||
			arg[0] == 'j' || arg[0] == 'J') &&
		arg[1] == '\0')
		screen()->option = 0;
	if ((!ft_strncmp(arg, "mandelbrot", ft_strlen(arg) + 1) ||
			arg[0] == 'j' || arg[0] == 'J') &&
		arg[1] == '\0')
		screen()->option = 1;
	return (1);
}

int	validate_arguments(char **argv)
{
	if (!&argv[1])
		return (1);
	if (!set_type(argv[0]))
		print_help_screen();
	return (0);
}

int	print_help_screen(void)
{
	ft_printf("=========== HELP SCREEN ===========\n");
	ft_printf("Usage: ./fractol [fractal] [ Axis_X value ] [ Axis_Y value ]\n");
	ft_printf("[m] >>> Mandelbrot\n");
	ft_printf("[j] >>> Julia\n");
	ft_printf("Axis value: [-2.0, 2.0]\n");
	ft_printf("=========== HELP SCREEN ===========\n");
	exit(2);
	return (2);
}
