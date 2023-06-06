#include "fractol.h"

/* void	change_pallete(t_win *screen)
{
	if (screen->color_mode + 1 < 2)
		screen->color_mode += 1;
	else
		screen->color_mode = 0;
	fracta_builder(screen);
	update_image_display(screen);
}

static void	move_fractal(int keycode, t_win *window)
{
	if (keycode == UP)
		window->constant_b += 0.1;
	if (keycode == DOWN)
		window->constant_b -= 0.1;
	if (keycode == LEFT)
		window->constant_a -= 0.1;
	if (keycode == RIGHT)
		window->constant_a += 0.1;
	fracta_builder(window);
	update_image_display(window);
}

void	interactions_events(int keycode, t_win *window)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == ESC)
		close_program(screen());
	if (keycode == PLUS)
		screen()->interactions += 10;
	if (keycode == MINUS)
		screen()->interactions -= 10;
	if (keycode == 49)
		change_pallete(screen());
	if (keycode == 51)
	{
		zoom_reset();
		fracta_builder(window);
		update_image_display(window);
	}
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		move_fractal(keycode, window);
} */