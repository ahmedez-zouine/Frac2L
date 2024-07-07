/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:18:21 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/06 20:18:23 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_start(char *argv[], t_fractol *fract)
{
	fract = malloc(sizeof(t_fractol));
	fract->myimg = malloc(sizeof(t_img));
	fract->zoom = 1.0;
	fract->iteration = 42;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	if (ft_strcmp(argv[1], "Julia") == 1)
	{
		if (ft_atof(argv[2]) == -42 || ft_atof(argv[3]) == -42)
		{
			ft_cleanup(fract);
			ft_putstr_fd(2, "Argument Error *__* ");
		}
		fract->real = ft_atof(argv[2]);
		fract->imag = ft_atof(argv[3]);
	}
	fract->name = argv[1];
	ft_mlxinit(fract);
	ft_display(fract);
	mlx_mouse_hook(fract->mlx_window, ft_zoom, fract);
	mlx_loop(fract->mlx_connect);
}

int	main(int argc, char *argv[])
{
	t_fractol	*fract;

	fract = NULL;
	if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot"))
		ft_start(argv, fract);
	else if (argc == 2 && ft_strcmp(argv[1], "Tricorn"))
		ft_start(argv, fract);
	else if (argc == 4 && ft_strcmp(argv[1], "Julia"))
		ft_start(argv, fract);
	else
		ft_putstr_fd(2, "Argument Error *__* ");
}
