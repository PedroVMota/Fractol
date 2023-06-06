/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 08:51:07 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/05 12:39:54 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"




/*
		~ set_data function:
		~ - Set the type of the fractal depending the parameter.
*/
static void set_type(char *av, t_fractal *all)
{
	if (ft_strncmp(av, "mandelbrot", ft_strlen("mandelbrot") + 1) == 0 || (av[0] == 'm' || av[0] == '0') && av[1] == '\0')
		all->type = MANDELBROT;
	if (ft_strncmp(av, "julia", ft_strlen("julia") + 1) == 0 || (av[0] == 'j' || av[0] == '1') && av[1] == '\0')
		all->type = JULIA;
}
/*
		~ What is kr and ki?
		~ kr and ki are the real and imaginary part of the complex number.
		~ They are the coordinates of the complex number in the complex plane.
		~ - set_data_julia function:
		~ - If the type is not JULIA or the number of arguments is 2, set the default values.
		~ - If the number of arguments is 3, close the system if the complex number is invalid.
		~ - If the number of arguments is 4, set the values of kr and ki.
		~ - If ki is out of range, close the system.
		~ - If kr is out of range, close the system.
*/
static void set_data(t_fractal *all, char **av, int ac)
{
	if(all->type != JULIA || ac == 2)
	{
		all->ki = - -0.766;
		all->kr = - -0.09;
		return ;
	}
	if(ac == 4)
		close_and_clean(2, "Not Enought Paramters", all);
	if(!ft_strchr(av[2], '.'))
		close_and_clean(2, "Invalid complex number", all);
	if(!ft_strchr(av[3], '.'))
		close_and_clean(2, "Invalid complex number", all);
	all->ki = ft_atof(av[2]);
	all->kr = ft_atof(av[3]);
	if((all->ki < -2 || all->ki > 2))
		close_and_clean(2, "Complex real is out of range [2, -2]", all);
	if((all->kr < -2 || all->kr > 2))
		close_and_clean(2, "Complex imaginary is out of range [2, -2]", all);
}

/*
	~ set_data function:
	~ - If the type is not JULIA, set the default values.
*/

void set_args(char **av, int ac, t_fractal *all)
{
	set_type(av[1], all);
	if(all->type == 0)
		close_and_clean(2, "Invalid fractal name", all);
	if(all->type != JULIA && ac > 3 || all->type == JULIA && ac > 5)
		close_and_clean(2, "Invalid number of arguments\n", all);
	set_data(all, av, ac);
	set_colors(all, av, ac);
}

void print_help_screen(void)
{
	printf("%sHello, welcome to the help screen%s\n", GRN, RESET);
	printf("%s=======================================%s\n", GRN, RESET);
	printf("\tMandelbrot:\n");
	printf("\t\tName options: mandelbrot | m | 0 |\n");
	printf("\t\t%s./fractol mandelbrot%s\n", RED, RESET);
	printf("%s=======================================%s\n", GRN, RESET);
	printf("\tJulian\n");
	printf("\t\tName options: julia | j | 1 |\n");
	printf("\t\tComplex: Float Number (mandatory have a \".\")\n");
	printf("\t\t%s./fractol julia \"0.8\", \"1.567\"%s\n", RED, RESET);
}