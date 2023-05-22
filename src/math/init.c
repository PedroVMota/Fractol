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

int	ft_fractal_mandelbro(t_complex *real_and_imaginary, int loopreal_and_imaginary,	int x)
{
	//f(x) = x2 + c
	int interactions = 0;
	real_and_imaginary->imaginary = 0;
	real_and_imaginary->real = 0;
	while (interactions < x)
	{
        
		interactions++;
	}
	return (interactions);
}