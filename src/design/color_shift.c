#include "fractol.h"

void	color_shift(int n, int x, int y, float color_shift)
{
	int red;
    int green;
    int blue;
    double t;
    int color;

    red = 0;
    green = 0;
    blue = 0;
    if (n < screen()->n)
    {
        t = (double)n / screen()->n;
        red = (int)(9 * (1 - t) * t * t * t * 255);
        green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    }
    // Apply color shift
    red = (red + (int)(color_shift * 255)) % 256;
    green = (green + (int)(color_shift * 255)) % 256;
    blue = (blue + (int)(color_shift * 255)) % 256;

    color = (red << 16) | (green << 8) | blue;
    place_pixel(screen(), x, y, color);
}