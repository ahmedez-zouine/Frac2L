/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:17:38 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/23 20:55:00 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mandelbrot(double *r, double *i, double rl, double im)
{
	double	tmp;

	tmp = (*r * *r) - (*i * *i) + rl;
	*i = (2 * *r * *i) + im;
	*r = tmp;
}

void	calc_tricorn(double *r, double *i, double rl, double im)
{
	double	tmp;

	tmp = (*r * *r) - (*i * *i) + rl;
	*i = (-2 * *r * *i) + im;
	*r = tmp;
}

void	calc_julia(double *r, double *i, t_fractol *fr)
{
	double	tmp;

	tmp = (*r * *r) - (*i * *i) + fr->real;
	*i = (2 * *r * *i) + fr->imag;
	*r = tmp;
}

int	in_frac(double rl, double im, t_fractol *fr)
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
