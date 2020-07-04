#include "fractol.h"

int		main(int ac, char **av)
{
	if (ac != 2)
		return(p_error(0));
	draw_check(av[1]);
	return (0);
}
