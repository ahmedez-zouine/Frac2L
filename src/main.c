/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:18:21 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/23 20:55:00 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_julia_params(char *argv[], t_fractol *fract)
{
	if (ft_strcmp(argv[1], "Julia") == 1)
	{
		if (ft_atof(argv[2]) == -42 || ft_atof(argv[3]) == -42)
		{
			free(fract->myimg);
			free(fract);
			ft_putstr_fd(2, "Error: Invalid Julia parameters.\n\n");
			print_help();
			exit(EXIT_FAILURE);
		}
		fract->real = ft_atof(argv[2]);
		fract->imag = ft_atof(argv[3]) * -1;
	}
}

void	ft_start(char *argv[])
{
	t_fractol	*fract;

	fract = malloc(sizeof(t_fractol));
	if (!fract)
		malloc_error(fract);
	fract->myimg = malloc(sizeof(t_img));
	if (!fract->myimg)
		malloc_error(fract);
	fract->zoom = 1.0;
	fract->iteration = 42;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	ft_init_julia_params(argv, fract);
	fract->name = argv[1];
	ft_mlxinit(fract);
	ft_display(fract);
	mlx_loop(fract->mlx_connect);
}

int	main(int argc, char *argv[])
{
	if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot"))
		ft_start(argv);
	else if (argc == 2 && ft_strcmp(argv[1], "Tricorn"))
		ft_start(argv);
	else if (argc == 4 && ft_strcmp(argv[1], "Julia"))
		ft_start(argv);
	else
	{
		print_help();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
