/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:57:54 by lconchit          #+#    #+#             */
/*   Updated: 2020/07/13 19:54:27 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int		color_magic(int i, double x, double y)
{
	unsigned int	color;
	double			magic;
	double			i2;
	t_color			c;

	magic = hypot(x, y);
	i2 = i + 1 - (log(2) / magic) / log(2);
	c.chan[0] = (unsigned char)(sin(0.026 * i2 + 4) * 230 + 25);
	c.chan[1] = (unsigned char)(sin(0.023 * i2 + 2) * 230 + 25);
	c.chan[2] = (unsigned char)(sin(0.01 * i2 + 1) * 230 + 25);
	color = (c.chan[0] << 16) + (c.chan[1] << 8) + c.chan[2] + 255;
	return (color);
}
