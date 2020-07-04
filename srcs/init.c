/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:58:44 by lconchit          #+#    #+#             */
/*   Updated: 2020/07/04 23:58:46 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_init(char *set, t_fr *fr)
{
	fr->mlx_ptr = mlx_init();
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	fr->img_data = mlx_get_data_addr(fr->img_ptr, &fr->bpp, &fr->line_size, &fr->endian);
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, set);
	fr->n = MIN_ITERATIONS;
	fr->x_prev = 0;
	fr->y_prev = 0;
	fr->x_min = -2.0;
	fr->x_max = 2.0;
	fr->y_min = WIN_HEIGHT / (double)WIN_WIDTH * fr->x_min;
	fr->y_max = WIN_HEIGHT / (double)WIN_WIDTH * fr->x_max;
	fr->jx = - 0.70176;
	fr->jy = - 0.3842;
	fr->scale = 1.0;
	fr->color_scheme = 0;
	ft_strequ(set, "Mandelbrot") ? fr->set = 1 : 0;
	ft_strequ(set, "Julia") ? fr->set = 2 : 0;
	ft_strequ(set, "Burningship") ? fr->set = 3 : 0;
	fr->fix = 1;
	return (1);
}
