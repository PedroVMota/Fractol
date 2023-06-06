#include "fractol.h"

static float	mc(float x)
{
	return ((x - 0) * (255 - 0) / (255 - 0) + 0);
}

static float	get_percentage(int inte, int max)
{
	return ((float)inte / (float)max * 100);
}

static int	pc(int percentage)
{
	return (mc(percentage));
}

static int	rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	zebra_pallete(t_win *main, int inte, int x, int y)
{
	int	interaction_percentage;

	interaction_percentage = get_percentage(inte, MAX_INTERACTIONS);
	if (interaction_percentage < 5)
		place_pixel(main, x, y, rgb(255, 0, 0, 0));
	else if (interaction_percentage < 15)
		place_pixel(main, x, y, rgb(255, mc(pc(10)), mc(pc(10)), mc(pc(10))));
	else if (interaction_percentage < 30)
		place_pixel(main, x, y, rgb(255, mc(pc(20)), mc(pc(20)), mc(pc(20))));
	else if (interaction_percentage < 40)
		place_pixel(main, x, y, rgb(255, mc(pc(30)), mc(pc(30)), mc(pc(30))));
	else if (interaction_percentage < 50)
		place_pixel(main, x, y, rgb(255, mc(pc(40)), mc(pc(40)), mc(pc(40))));
	else if (interaction_percentage < 60)
		place_pixel(main, x, y, rgb(255, mc(pc(50)), mc(pc(50)), mc(pc(50))));
	else if (interaction_percentage < 70)
		place_pixel(main, x, y, rgb(255, mc(pc(60)), mc(pc(60)), mc(pc(60))));
	else if (interaction_percentage < 80)
		place_pixel(main, x, y, rgb(255, mc(pc(70)), mc(pc(70)), mc(pc(70))));
	else if (interaction_percentage < 90)
		place_pixel(main, x, y, rgb(255, mc(pc(80)), mc(pc(80)), mc(pc(80))));
	else if (interaction_percentage < 100 || interaction_percentage == 100
			|| interaction_percentage > 100)
		place_pixel(main, x, y, rgb(255, mc(pc(90)), mc(pc(90)), mc(pc(90))));
}
