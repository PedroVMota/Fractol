#include "fractol.h"

static int	rgb(int r, int g, int b)
{
	int	color;

	color = 0 << 24 | r << 16 | g << 8 | b;
	if (color < 0)
		color = -color;
	return (color);
}

static void	set_background(t_win *screen, int n, int x, int y)
{
	int	colors[6];

	colors[0] = rgb(255, 57, 93);
	colors[1] = rgb(255, 160, 93);
	colors[2] = rgb(227, 128, 187);
	colors[3] = rgb(255, 255, 255);
	if (n >= 0 && n < 3)
		place_pixel(screen, x, y, rgb(255, 57, 93));
	if (n >= 3 && n < 10)
		place_pixel(screen, x, y, rgb(255, 160, 93));
	if (n >= 10 && n < 20)
		place_pixel(screen, x, y, rgb(227, 128, 187));
}

void	rainbow_pallete(t_win *screen, int n, int x, int y)
{
	set_background(screen, n, x, y);
}