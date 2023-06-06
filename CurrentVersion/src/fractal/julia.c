#include "fractol.h"

int julia(t_win *screen, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_INTERACTIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + screen->cr;
		zr = zr * zr - zi * zi + screen->ci;
		zi = tmp;
		n++;
	}
	return (n);
}