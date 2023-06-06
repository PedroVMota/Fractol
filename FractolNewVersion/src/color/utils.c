#include "fractol.h"

void	fill_color(t_fractal *all, int color, int stripe)
{
	int	i;

	i = 0;
	while (i < MAX_INTERACTIONS)
	{
		all->palete[i] = color;
		i += stripe;
	}
}

/*
	Convert Color to Percent Function:
	-> Converts a color to a percentage.
	-> The percentage is a double between 0 and 100.
	-> The color is an integer.
	-> The color is converted to RGB.
	-> The percentage is converted to RGB.
	-> The percentage is added to the color.
	-> The new color is returned.
*/
int	convert_color_to_percent(int color, double percent)
{
	int		rgb[3];
	int		trgb[3];
	double	percentage;

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	percentage = (percent / 100) * 256;
	trgb[0] = (rgb[0] + percentage) - 256;
	trgb[1] = (rgb[1] + percentage) - 256;
	trgb[2] = (rgb[2] + percentage) - 256;
	return (0xFF << 24 | trgb[0] << 16 | trgb[1] << 8 | trgb[2]);
}
/*
	Color Blender Function:
	-> Blends two colors together.
	-> The fraction is the percentage of the final color.
	-> The fraction is a double between 0 and 1.
	Shifting the bits of the colors to get the RGB values.
	-> shifting 16 bits to the right to get the red value.
	-> shifting 8 bits to the right to get the green value.
	-> shifting 0 bits to the right to get the blue value.
*/
int	color_blender(int color_beggin, int final_color, double fraction)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((color_beggin >> 16) & 0xFF);
	start_rgb[1] = ((color_beggin >> 8) & 0xFF);
	start_rgb[2] = ((color_beggin >> 0) & 0xFF);
	end_rgb[0] = ((final_color >> 16) & 0xFF);
	end_rgb[1] = ((final_color >> 8) & 0xFF);
	end_rgb[2] = ((final_color >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}


/*
	Set Monochromatic Color Function:
	-> Changes the color of the fractal to a single color.
	-> White when close to the border of the fractal.
	-> Black to the color wanted.
*/
void set_monocromatic_color(t_fractal *all, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;


	color1 = 0x000000;
	color2 = color;
	i = 0;
	while(i < MAX_INTERACTIONS)
	{
		j = 0;
		while(j < (MAX_INTERACTIONS / 2))
		{
			fraction = (double)j / (double)(MAX_INTERACTIONS / 2);
			all->palete[i + j] = color_blender(color1, color2, fraction);
			j++;
		}
		color1 = color2;
		color2 = 0x00ffffff;
		i += j;
	}
	all->palete[MAX_INTERACTIONS - 1] = 0;
}

/*
	Rainbow_set_color Function:
	-> Changes the color of the fractal to a rainbow pattern.
	-> The rainbow pattern is made of 4 colors.
	-> The first color is black.
	-> The second color is the color wanted.
	-> The third color is the color wanted but with 50% of transparency.
	-> The fourth color is white.
*/
void rainbow_set_color(t_fractal *all, int colors[4], int n)
{
	int i;
	int j;
	int x;
	int fraction;

	fraction = 0;
	x = 0;
	i = 0;
	while (i < MAX_INTERACTIONS)
	{
		j = 0;
		while ((i + j) < MAX_INTERACTIONS && j < (MAX_INTERACTIONS / (n - 1)))
		{
			fraction = (double)j / (MAX_INTERACTIONS / (n - 1));
			all->palete[i + j] = color_blender(colors[x], colors[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
	all->palete[MAX_INTERACTIONS - 1] = 0;
}
