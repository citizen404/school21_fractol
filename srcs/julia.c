#include "fractol.h"

int			check_julia(t_fr *fr)
{
	int		n;
	double		a;
	double		b;
	double		temp;

	n = 0;
	a = fr->re_c;
	b = fr->im_c;
	while (a * a + b * b < 4 && n < fr->n)
	{
		temp = a * a - b * b;
		b = 2 * a * b + fr->jy;
		a = temp + fr->jx;
		n++;
	}
	return (n);
}

void			draw_julia(t_fr *fr)
{
	unsigned int	color;
	int		x;
	int		y;

	x = 0;
	while (x < WIN_WIDTH)
	{	
		y = 0;
		fr->re_c = map(x, 0, WIN_WIDTH, fr->x_min, fr->x_max);
		while (y < WIN_HEIGHT)
		{
			fr->im_c = map(y, 0, WIN_HEIGHT, fr->y_min, fr->y_max);
			color = map(check_julia(fr), 0, fr->n, 0, 255);
			fr->color_scheme != 0 ? color = color_magic(fr->color_scheme * color, x, y) : 0;
			fr->img_data[(x + y * WIN_WIDTH) * 4] = color;
			fr->img_data[(x + y * WIN_WIDTH) * 4 + 1] = color >> 8;
			fr->img_data[(x + y * WIN_WIDTH) * 4 + 2] = color >> 16;
			fr->img_data[(x + y * WIN_WIDTH) * 4 + 3] = color >> 24;
			y++;
		}
		x++;
	}
}