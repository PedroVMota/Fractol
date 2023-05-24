#include "fractol.h"

double map(float x, float input_min, float input_max, float output_min,
		   float output_max)
{
	return (((x - input_min) / (input_max - input_min)) * (output_max - output_min) + output_min);
}

int ft_fractal_mandelbrot(t_win *screen, int interaction_max, int pixel_x,
						  int pixel_y)

{
	int interactions;
	double ratio_x;
	double ratio_y;
	double real_part;
	double imaginary_part;
	double constant_a;
	double constant_b;

	interactions = 0;
	ratio_x = map(pixel_x, 0, screen->width, -2, 2);
	ratio_y = map(pixel_y, 0, screen->height, -2, 2);
	constant_a = ratio_x;
	constant_b = ratio_y;
	while (interactions < interaction_max)
	{
		real_part = ratio_x * ratio_x - ratio_y * ratio_y;
		imaginary_part = 2 * ratio_x * ratio_y;

		ratio_x = real_part + constant_a;
		ratio_y = imaginary_part + constant_b;
		if (fabs(ratio_x + ratio_y) > 4.0)
			break;
		interactions++;
	}
	return (interactions);
}

int ft_fractal_julia(t_win *screen, int interaction_max, int pixel_x, int pixel_y)
{
	int interactions;
	double ratio_x;
	double ratio_y;
	double real_part;
	double imaginary_part;
	double constant_a = -0.8;  // Change the Julia constant 'a' to your desired value
	double constant_b = 0.156; // Change the Julia constant 'b' to your desired value

	interactions = 0;
	ratio_x = map(pixel_x, 0, screen->width, -2, 2);
	ratio_y = map(pixel_y, 0, screen->height, -2, 2);

	while (interactions < interaction_max)
	{
		real_part = ratio_x * ratio_x - ratio_y * ratio_y;
		imaginary_part = 2 * ratio_x * ratio_y;

		ratio_x = real_part + constant_a;
		ratio_y = imaginary_part + constant_b;

		if (fabs(ratio_x + ratio_y) > 4.0)
			break;

		interactions++;
	}

	return interactions;
}

void mandelbro_calculation(t_win *screen)
{
	int inte;

	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			inte = ft_fractal_mandelbrot(screen, screen->interactions, x, y);
			color_palette(screen, inte, x, y);
		}
	}
}

void julia_calculation(t_win *screen)
{
	int inte;

	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			inte = ft_fractal_julia(screen, screen->interactions, x, y);
			color_palette(screen, inte, x, y);
		}
	}
}