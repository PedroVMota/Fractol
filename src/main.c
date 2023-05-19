#include "fractol.h"

t_win	new_program(int width, int height, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, width, height, str), width,
		height});
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

int	main(void)
{
	t_win window;
	t_img pixel;

	window = new_program(500, 500, "Fractol");
	if (!window.mlx_ptr || !window.win_ptr)
		return (2);
	mlx_pixel_put(window.mlx_ptr, window.win_ptr, 250, 250, 0);
	pixel = new_img(300,200, window);

	printf("Let's Find out what's inside our structure :D\n");
	printf("bpp		: [%d]\n", pixel.bpp);
	printf("line_len	: [%d]\n", pixel.line_len);
	printf("endian		: [%d]\n", pixel.endian);
	printf("addr		: [%p]\n", pixel.addr);
	ft_memcpy(pixel.addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 16*4);
	mlx_put_image_to_window (pixel.win.mlx_ptr, pixel.win.win_ptr, pixel.img_ptr, 10, 10);
	mlx_loop(window.mlx_ptr);
	return (0);
}