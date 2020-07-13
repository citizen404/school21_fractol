/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:59:20 by lconchit          #+#    #+#             */
/*   Updated: 2020/07/13 20:06:07 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_HEIGHT 600
# define WIN_WIDTH 800

# define DX 10
# define DY 100

# define MIN_ITERATIONS 40
# define K_DEEP 0.005
# define COLOR_BACKGR 0x000000

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

# define ESC 53
# define RESET 15
# define FIX 3
# define CS1 18
# define CS2 19
# define CS3 20

typedef	struct		s_color
{
	unsigned char	chan[3];
}					t_color;

typedef struct		s_fr
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*img_ptr;
	char			*img_data;
	double			scale;
	double			jx;
	double			jy;
	int				set;
	int				fix;
	double			x_prev;
	double			y_prev;
	double			x_min;
	double			y_min;
	double			x_max;
	double			y_max;
	double			re_c;
	double			im_c;
	int				n;
	int				color_scheme;
	int				bpp;
	int				line_size;
	int				endian;
}					t_fr;

double				map(int val, int s1, int f1, double s2, double f2);
int					check_mandelbrot(t_fr *fr);
int					check_julia(t_fr *fr);
int					check_burningship(t_fr *fr);
void				draw_check(char *set_name);
void				draw_mandelbrot(t_fr *fr);
void				draw_julia(t_fr *fr);
void				draw_burningship(t_fr *ft);
void				redraw(t_fr *fr);
int					key_hook(int key, t_fr *fr);
int					mouse_hook(int button, int x, int y, t_fr *fr);
int					mouse_move(int x, int y, t_fr *fr);
void				zoom_in(t_fr *fr, int x, int y);
void				zoom_out(t_fr *fr, int x, int y);
void				reset(t_fr *fr);
void				fractol_exit(t_fr *fr);
int					fractol_init(char *set, t_fr *fr);
int					p_error(int i);
unsigned int		color_magic(int i, double x, double y);

#endif
