/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:27:17 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/01 22:54:02 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_INTERACTIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

/*
	The Mandelbrot formula operates on complex numbers:
At each iteration, Z is squared.
    Z = Z * Z + c
If the result tends towards infinity, it is not part of
the Mandelbrot set. If the result remains small over several iterations,
the number is considered part of the set.

Examples using regular numbers:
    ex.: c = 1
        Z =  0
        Z =  0 *  0 + 1 = 1
        Z =  1 *  1 + 1 = 2
        Z =  2 *  2 + 1 = 5
        Z =  5 *  5 + 1 = 26
        Z = 26 * 26 + 1 = 677
        ... Grows towards infinity.
        Therefore, 1 is NOT part of the Mandelbrot set.

    ex.2: c = -1
        Z =    0
        Z =    0 *    0 + (-1) = -1
        Z = (-1) * (-1) + (-1) =  0
        Z =    0 *    0 + (-1) = -1
        ... Result oscillates between -1 and 0
        Therefore, -1 is part of the Mandelbrot set.

	In this computation, we cannot iterate to infinity, but it is safe to say
	that if the absolute value of Z exceeds 2, it will tend towards infinity
	and the number will not be part of the Mandelbrot set.

	Since we are working with complex numbers, we need to calculate both
	the real number Zr and the imaginary number Zi and evaluate them together.
	Multiplying two complex numbers is complex:
	(a + bi)2   = (a + bi) * (a + bi)
				= (a * a) + (a * bi) + (a * bi) + (bi * bi)
				= (a * a) - (b * b) + 2 * (a * b)
	Thus, the multiplication formula for the imaginary part is:
					(a * a) - (b * b)
	And the multiplication formula for the real part is:
					2 * a * b
*/