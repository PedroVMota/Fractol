#include "fractol.h"

int	julia_shift(int x, int y, t_fractal *all)
{
	all->kr = all->min_r + (double)x * (all->max_r - all->min_r) / WIDTH;
	all->ki = all->max_i + (double)y * (all->min_i - all->max_i) / HEIGHT;
	render(all);
	return (0);
}

int	julia(t_fractal *all, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_INTERACTIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + all->ki;
		zr = zr * zr - zi * zi + all->kr;
		zi = tmp;
		n++;
	}
	return (n);
}

/*
	The Julia set is intimately connected to the Mandelbrot set:
	they share the same formula. The distinction lies in the complex
	number utilized in the computation.

	For the Mandelbrot set, we start with 0 as the initial value for zr and zi,
	and subsequently add the pixel coordinates (cr and ci) during each iteration.

	On the contrary, Julia begins with the pixel coordinates as zr and zi,
	and introduces an additional complex number (kr and ki) during each iteration.

	The values of kr and ki determine the shape assumed by the Julia set.
	If kr + ki lies within the Mandelbrot set, Julia will exhibit a continuous,
	solid shape. If kr + ki is outside the Mandelbrot set, the Julia fractal
	will manifest as a disconnected collection of distinct islands.
	If kr + ki corresponds to a point near the boundary of the Mandelbrot fractal,
	the Julia fractal will exhibit the same patterns observed at that point
	in the Mandelbrot fractal.
*/