#include "fractol.h"

static float map_color(float x, float in_min, float in_max)
{
	return ((x - in_min) * (255 - 0) / (in_max - in_min) + 0);
}

static float get_percentage(int inte, int max)
{
	return ((float)inte / (float)max * 100);
}

static int gen_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	zebra_pallete(t_win *main, int inte, int x, int y)
{
	float	t;
	int	color;

	color = 0;
	t = get_percentage(inte, MAX_INTERACTIONS);
	if (t <= 63.75)
	{
		color = gen_trgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
				map_color(t, 0, 63.75));
	}
	else if (t <= 127.5)
	{
		t -= 63.75;
		color = gen_trgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
				map_color(t, 0, 63.75));
	}
	else if (t <= 191.25)
	{
		t -= 127.5;
		color = gen_trgb(255, map_color(t, 0, 191.25), map_color(t, 0, 191.25),
				map_color(t, 0, 191.25));
	}
	else
	{
		t -= 191.25;
		color = gen_trgb(255, map_color(t, 0, 63.75), map_color(t, 0, 63.75),
				map_color(t, 0, 63.75));
	}
	place_pixel(main, x, y, color);
}
