#include "fractol.h"

int	ft_fractal_mandelbrot(t_win *screen, int interaction_max)
{
	//f(x) = x2 + c
	print_data(screen);

	// printf("Ratio x_start: %f\n", screen->ratio->x_start);
	// printf("Ratio x_end: %f\n", screen->ratio->x_end);
	// printf("Ratio y_start: %f\n", screen->ratio->y_start);
	// printf("Ratio y_end: %f\n", screen->ratio->y_end);
	int interactions = 0;
	double old_real = screen->formula->real;
	double old_imaginary = screen->formula->imaginary;

	while (interactions < interaction_max)
	{
		double a = 
		interactions++;
	}
	return (interactions);
}