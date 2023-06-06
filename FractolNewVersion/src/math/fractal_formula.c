/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_formula.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:46:44 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/05 12:56:02 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Set Pixel Function:
	-> Sets the color pattern for the fractal.
	The MLX image is composed of 32 bits per pixel.
	Color ints are stored from right to left, here, and are in
	the form of 0xAARRGGBB. 8 bits encode each color component,
	Alpha (Transparency), Red, Green and Blue.
	Bit shifting:
		-> BB >> 0   (0x000000BB)
		-> GG >> 8   (0x0000GG00)
		-> RR >> 16  (0x00RR0000)
		-> AA >> 24  (0xAA000000)
*/

void	set_color(t_fractal *all, int x, int y, int color)
{
		all->addr[x * 4 + y * WIDTH * 4] = color;
		all->addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		all->addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		all->addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}


/*
	Set Fractal Calculation Function:
	-> Calculates the fractal formula.
*/
static int	set_fractal_calculation(t_fractal *all, double pr, double pi)
{
	int	nb_iter;
	if (all->type == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (all->type == JULIA)
		nb_iter = julia(all, pr, pi);
	return (nb_iter);
}

/*
	Render Function:
	-> Calculates the fractal formula.
	-> Sets the color pattern for the fractal.
	-> Pr Stands for Real Part.
	-> Pi Stands for Imaginary Part.
*/
void	render(t_fractal *all)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(all->mlx, all->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = all->min_r + (double)x * (all->max_r - all->min_r) / WIDTH;
			pi = all->max_i + (double)y * (all->min_i - all->max_i) / HEIGHT;
			nb_iter = set_fractal_calculation(all, pr, pi);
			set_color(all, x, y, all->palete[nb_iter]);
		}
	}
	printf("Rendered >> %s\n", all->addr);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}