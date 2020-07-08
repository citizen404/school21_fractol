/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:58:12 by lconchit          #+#    #+#             */
/*   Updated: 2020/07/04 23:58:14 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_exit(t_fr *fr)
{
	mlx_destroy_image(fr->mlx_ptr, fr->img_ptr);
	mlx_destroy_window(fr->mlx_ptr, fr->win_ptr);
	free(fr);
	fr = NULL;
	exit(0);
}

void	zoom_in(t_fr *fr, int x, int y)
{
	double x_n;
	double y_n;

	if (x > 0 && y > 0)
	{
		x_n = map(x, 0, WIN_WIDTH, fr->x_min, fr->x_max);
		y_n = map(y, 0, WIN_HEIGHT, fr->y_min, fr->y_max);
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

void	zoom_out(t_fr *fr, int x, int y)
{
	double x_n;
	double y_n;

	if (fr->scale < 1)
	{
		x_n = map(x, 0, WIN_WIDTH, fr->x_min, fr->x_max);
		y_n = map(y, 0, WIN_HEIGHT, fr->y_min, fr->y_max);
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

void	reset(t_fr *fr)
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

int	key_hook(int key, t_fr *fr)
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

int	mouse_hook(int button, int x, int y, t_fr *fr)
{ 
	if (button == 5)
		zoom_in(fr, x, y);
	if (button == 4)
		zoom_out(fr, x, y);
	mlx_clear_window(fr->mlx_ptr,fr->win_ptr);
	redraw(fr);
	return (1);
}

int	mouse_move(int x, int y, t_fr *fr)
{
	if (fr->fix)
		if (x < WIN_WIDTH && y < WIN_HEIGHT)
		{
			fr->jx = map(x, 0, WIN_WIDTH, -1, 1);
			fr->jy = map(y, 0, WIN_HEIGHT, -1, 1);
		}
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	redraw(fr);
	return (1);
}
