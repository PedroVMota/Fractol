#include "fractol.h"

/* void ft_fractal_computation(t_complex *real_and_imaginary,
		int n_interactionreal_and_imaginary, int *i)
{
    int		temp;

    real_and_imaginary->real = 0;
    real_and_imaginary->imaginary = 0;
    *i = 0;
    while (real_and_imaginary->real * real_and_imaginary->real
		+ real_and_imaginary->imaginary * real_and_imaginary->imaginary < 4
		&& *i < n_interactionreal_and_imaginary)
    {
        temp = pow(real_and_imaginary->real, 2)
	- pow(real_and_imaginary->imaginary, 2) + real_and_imaginary->real;
        real_and_imaginary->imaginary = 2 * real_and_imaginary->real
	* real_and_imaginary->imaginary + real_and_imaginary->imaginary;
        real_and_imaginary->real = temp;
        *i += 1;
    }
} */

int	ft_fractal_mandelbrot(t_win *screen, int interaction_max)
{
	//f(x) = x2 + c

	ft_printf("==================\n");
	ft_printf("Offset X  Start %d of %d\n", screen->ratio->x_start, screen->ratio->x_end);
	ft_printf("Offset Y  Start %d of %d\n", screen->ratio->y_start, screen->ratio->y_end);
	ft_printf("==================\n");
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