/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:58:21 by lconchit          #+#    #+#             */
/*   Updated: 2020/07/04 23:58:24 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	p_error(int i)
{
	if (i == 0)
		ft_putstr("Usage: ./fractol set_name\n");
	if (i == 1)
		ft_putstr("ERR: Memory allocation fault\n");
	if (i == 2)
		ft_putstr("ERR: Invalid option\n");
	if (i == 3)
		ft_putstr("ERR: Initialization fault\n");
	return (0);
}
