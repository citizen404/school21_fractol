#include "fractol.h"

void		zoom_in(t_fr *fr, int x, int y)
{
	double	x_n;
	double	y_n;

	if (x > 0 && y > 0)
	{
		x_n = map_fr(x, WIN_WIDTH, fr->x_min, fr->x_max);
		y_n = map_fr(y, WIN_HEIGHT, fr->y_min, fr->y_max);
		fr->scale -= K_DEEP;
		fr->x_prev = x_n - x_n * fr->scale;
		fr->y_prev = y_n - y_n * fr->scale;
		fr->x_min = fr->x_min * fr->scale + fr->x_prev;
		fr->x_max = fr->x_max * fr->scale + fr->x_prev;
		fr->y_min = fr->y_min * fr->scale + fr->y_prev;
		fr->y_max = fr->y_max * fr->scale + fr->y_prev;
		fr->n += 2;
	}
}

void		zoom_out(t_fr *fr, int x, int y)
{
	double	x_n;
	double	y_n;

	if (fr->scale < 1)
	{
		x_n = map_fr(x, WIN_WIDTH, fr->x_min, fr->x_max);
		y_n = map_fr(y, WIN_HEIGHT, fr->y_min, fr->y_max);
		fr->x_prev = x_n - x_n / fr->scale;
		fr->y_prev = y_n - y_n / fr->scale;
		fr->x_min = fr->x_min / fr->scale + fr->x_prev;
		fr->x_max = fr->x_max / fr->scale + fr->x_prev;
		fr->y_min = fr->y_min / fr->scale + fr->y_prev;
		fr->y_max = fr->y_max / fr->scale + fr->y_prev;
		fr->scale += K_DEEP;
		fr->n -= 2;
	}
}

int			mouse_hook(int button, int x, int y, t_fr *fr)
{
	if (button == 5)
		zoom_in(fr, x, y);
	if (button == 4)
		zoom_out(fr, x, y);
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	redraw(fr);
	return (1);
}

int			mouse_move(int x, int y, t_fr *fr)
{
	if (fr->fix)
		if (x < WIN_WIDTH && y < WIN_HEIGHT)
		{
			fr->jx = map_fr(x, WIN_WIDTH, -1, 1);
			fr->jy = map_fr(y, WIN_HEIGHT, -1, 1);
		}
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	redraw(fr);
	return (1);
}
