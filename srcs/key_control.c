/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:58:12 by lconchit          #+#    #+#             */
/*   Updated: 2020/07/13 19:52:45 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractol_exit(t_fr *fr)
{
	mlx_destroy_image(fr->mlx_ptr, fr->img_ptr);
	mlx_destroy_window(fr->mlx_ptr, fr->win_ptr);
	free(fr);
	fr = NULL;
	exit(0);
}

void		reset(t_fr *fr)
{
	fr->scale = 1.0;
	fr->x_min = -2.0;
	fr->x_max = 2.0;
	fr->jx = -0.70176;
	fr->jy = -0.3842;
	fr->x_prev = 0;
	fr->y_prev = 0;
	fr->color_scheme = 0;
	fr->y_min = WIN_HEIGHT / (double)WIN_WIDTH * fr->x_min;
	fr->y_max = WIN_HEIGHT / (double)WIN_WIDTH * fr->x_max;
	fr->n = MIN_ITERATIONS;
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	redraw(fr);
}

int			key_hook(int key, t_fr *fr)
{
	if (key == ESC)
		fractol_exit(fr);
	if (key == RESET)
		reset(fr);
	if (key == FIX)
		fr->fix = (fr->fix == 0) ? 1 : 0;
	if (key == CS1)
		fr->color_scheme = 1;
	if (key == CS2)
		fr->color_scheme = 2;
	if (key == CS3)
		fr->color_scheme = 3;
	if (key == CS1 || key == CS2 || key == CS3)
		redraw(fr);
	return (1);
}
