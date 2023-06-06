/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:16:59 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/05 12:38:53 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_ishexdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	c = ft_toupper(c);
	if (c >= 'A' && c <= 'F')
		return (c);
	else
		return (0);
}

static int ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r')
		return (c);
	else
		return (0);
}

/*
	Mode Color Function:
	-> Sets the color pattern for the fractal.
	-> The color pattern is set by the user.
*/
void color_mode(t_fractal *all)
{
	if (all->color_pattern == 2)
		black_and_white(all, all->color);
	/* else if (all->color_pattern == 3)
		set_color_triad(all, all->color);
	else if (all->color_pattern == 4)
		set_color_tetra(all, all->color);
	else
		color_ultimate_saike(all); */
}

static int	skip_space_sign_0x(char *color)
{
	int	i;

	i = 0;
	while (ft_isspace(color[i]))
		i++;
	if (color[i] == '+')
		i++;
	if (color[i] == '0' && (color[i + 1]
			&& (color[i + 1] == 'x' || color[i] == 'X')))
		i = i + 2;
	return (i);
}



static int	ft_atox_color(t_fractal *all, char *color)
{
	int	i;
	int	x;
	int	n;

	n = 0;
	i = 0;
	i = skip_space_sign_0x(color);
	x = 0;
	while (color[i] && ft_ishexdigit(color[i]))
	{
		if (ft_isdigit(color[i]))
			n = (n * 16) + (color[i] - '0');
		else
			n = (n * 16) + (ft_toupper(color[i]) - 'A' + 10);
		i++;
		x++;
	}
	if (x == 6 && !color[i])
		return (n);
	else
		close_and_clean(2, "Hex color is not valid!", all);
	return (-1);
}


void set_colors(t_fractal *all, char **av, int ac)
{
	if (all->type == JULIA && ac == 5)
		all->color = ft_atox_color(all, av[4]);
	else if (all->type != JULIA && ac == 3)
		all->color = ft_atox_color(all, av[2]);
	if (ac == 2 || (all->type == JULIA && ac == 4))
		all->color = 0x9966FF;
}