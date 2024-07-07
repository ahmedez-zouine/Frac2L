/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:40:45 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/07 09:40:54 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}

void	calc_julia(double *r, double *i, t_fractol *fr)
{
	double	tmp;

	tmp = (*r * *r) - (*i * *i) + fr->real;
	*i = (2 * *r * *i) + fr->imag;
	*r = tmp;
}
