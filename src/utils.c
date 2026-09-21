/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:18:49 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/23 20:55:00 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr_fd(int fd, char *string)
{
	int	i;

	i = 0;
	while (string && string[i])
	{
		write(fd, &string[i], 1);
		i++;
	}
}

void	ft_cleanup(t_fractol *fr)
{
	if (!fr)
		return ;
	if (fr->myimg)
	{
		if (fr->myimg->img_ptr)
			mlx_destroy_image(fr->mlx_connect, fr->myimg->img_ptr);
		free(fr->myimg);
	}
	if (fr->mlx_window)
		mlx_destroy_window(fr->mlx_connect, fr->mlx_window);
	if (fr->mlx_connect)
	{
#ifdef __linux__
		mlx_destroy_display(fr->mlx_connect);
#endif
		free(fr->mlx_connect);
	}
	free(fr);
}

void	print_help(void)
{
	ft_putstr_fd(2, "╔═══════════════════════════════════════════════╗\n");
	ft_putstr_fd(2, "║               Frac2L - Usage Guide            ║\n");
	ft_putstr_fd(2, "╚═══════════════════════════════════════════════╝\n\n");
	ft_putstr_fd(2, "Available Fractals:\n");
	ft_putstr_fd(2, "  1. Mandelbrot\n");
	ft_putstr_fd(2, "  2. Tricorn\n");
	ft_putstr_fd(2, "  3. Julia <real> <imag>\n\n");
	ft_putstr_fd(2, "Examples:\n");
	ft_putstr_fd(2, "  ./fractol Mandelbrot\n");
	ft_putstr_fd(2, "  ./fractol Tricorn\n");
	ft_putstr_fd(2, "  ./fractol Julia 0.0 -1.0\n");
	ft_putstr_fd(2, "  ./fractol Julia -0.8 0.156\n");
	ft_putstr_fd(2, "  ./fractol Julia -0.4 0.6\n\n");
	ft_putstr_fd(2, "Controls:\n");
	ft_putstr_fd(2, "  Mouse Scroll   : Zoom In / Out\n");
	ft_putstr_fd(2, "  Arrow Keys     : Pan / Move\n");
	ft_putstr_fd(2, "  + / -          : Increase / Decrease Iterations\n");
	ft_putstr_fd(2, "  ESC / Window X : Exit\n");
}
