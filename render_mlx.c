/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:17:38 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/06 20:17:41 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc_tricorn(double *r, double *i, double rl, double im)
{
	double	tmp;

	tmp = (*r * *r) - (*i * *i) + rl;
	*i = (-2 * *r * *i) + im;
	*r = tmp;
}

static void	calc_mandelbrot(double *r, double *i, double rl, double im)
{
	double	tmp;

	tmp = (*r * *r) - (*i * *i) + rl;
	*i = (2 * *r * *i) + im;
	*r = tmp;
}

static int	in_frac(double rl, double im, t_fractol *fr)
{
	double	r;
	double	i;
	int		it;

	r = rl;
	i = im;
	it = 0;
	while (it < fr->iteration && (r * r) + (i * i) <= 4.0)
	{
		if (ft_strcmp("Julia", fr->name) == 1)
			calc_julia(&r, &i, fr);
		else if (ft_strcmp("Tricorn", fr->name) == 1)
			calc_tricorn(&r, &i, rl, im);
		else
			calc_mandelbrot(&r, &i, rl, im);
		it++;
	}
	return (it);
}

static int	ft_in_col(int x, int y, t_fractol *fr)
{
	double	r;
	double	im;
	int		it;

	r = (map(x, -2.0, 2.0, WIDTH) + fr->shift_x) * fr->zoom;
	im = (map(y, 2.0, -2.0, HEIGHT) + fr->shift_y) * fr->zoom;
	it = in_frac(r, im, fr);
	if (it == fr->iteration)
		return (0x000000);
	return (map(it, 0xFFFFFF, 0xFF00FF, fr->iteration));
}

void	ft_display(t_fractol *fr)
{
	int	x;
	int	y;
	int	pix;

	if (fr->myimg->img_ptr)
		mlx_destroy_image(fr->mlx_connect, fr->myimg->img_ptr);
	fr->myimg->img_ptr = mlx_new_image(fr->mlx_connect, WIDTH, HEIGHT);
	fr->myimg->pixels_ptr = mlx_get_data_addr(fr->myimg->img_ptr,
			&fr->myimg->bpp, &fr->myimg->line_len, &fr->myimg->endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pix = ft_in_col(x, y, fr);
			*(int *)(fr->myimg->pixels_ptr + x * fr->myimg->bpp / 8 + y
					* fr->myimg->line_len) = pix;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx_connect, fr->mlx_window, fr->myimg->img_ptr,
		0, 0);
}
