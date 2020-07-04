#include "fractol.h"

double		map(int val, int s1, int f1, double s2, double f2)
{
	return (((val - s1) / ((double)f1 - s1)) * (f2 - s2) + s2);
}

void		redraw(t_fr *fr)
{
	int	i;

	fr->set == 1 ? draw_mandelbrot(fr) : 1;
	fr->set == 2 ? draw_julia(fr) : 1;
	fr->set == 3 ? draw_burningship(fr) : 1;
	i = mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}

void		draw_check(char *set_name)
{
	t_fr	*fr;

	if (!(ft_strequ("Mandelbrot", set_name) || ft_strequ("Julia", set_name) || ft_strequ("Burningship", set_name)))
		exit(p_error(2));
	if (!(fr = (t_fr *)ft_memalloc(sizeof(t_fr))))
		{
			free(fr);
			fr = NULL;
			exit(p_error(1));
		}
	if (!(fractol_init(set_name, fr)))
		{
			free(fr);
			fr = NULL;
			exit(p_error(3));
		}
	redraw(fr);
	mlx_key_hook(fr->win_ptr, key_hook, fr);
	mlx_mouse_hook(fr->win_ptr, mouse_hook, fr);
	mlx_hook(fr->win_ptr, 6, 1L << 6, mouse_move, fr);
	mlx_loop(fr->mlx_ptr);
}