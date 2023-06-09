#include "fractol.h"

static int	rgb(int r, int g, int b)
{
	int	color;

	color = 0 << 24 | r << 16 | g << 8 | b;
	if (color < 0)
		color = -color;
	return (color);
}

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
	if (n < MAX_INTERACTIONS)
	{
		t = (double)n / MAX_INTERACTIONS;
		red = (int)(9 * (1 - t) * t * t * t * 255);
		green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	color = (red << 16) | (green << 8) | blue;
	place_pixel(screen, x, y, color);
}
