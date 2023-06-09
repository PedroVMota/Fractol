#include "fractol.h"

void	rainbow_palette(t_win *screen, int n, int x, int y)
{
	int		red;
	int		green;
	int		blue;
	double	t;
	int		color;

	red = 0;
	green = 0;
	blue = 0;
	if (n < screen->n)
	{
		t = (double)n / screen->n;
		red = (int)(9 * (1 - t) * t * t * t * 255);
		green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	color = (red << 16) | (green << 8) | blue;
	place_pixel(screen, x, y, color);
}
