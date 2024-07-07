/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:19:31 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/06 20:19:34 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_window(t_fractol *fr)
{
	ft_cleanup(fr);
	exit(0);
}

int	ft_key_hook(int keycode, t_fractol *fr)
{
	if (65307 == keycode)
		ft_close_window(fr);
	else if (keycode == 65451)
		fr->iteration++;
	else if (keycode == 65453)
		fr->iteration--;
	else if (keycode == 65361)
		fr->shift_x += 0.2;
	else if (keycode == 65362)
		fr->shift_y -= 0.2;
	else if (keycode == 65363)
		fr->shift_x -= 0.2;
	else if (keycode == 65364)
		fr->shift_y += 0.2;
	ft_display(fr);
	return (0);
}

int	ft_zoom(int wheel, int x, int y, t_fractol *fr)
{
	(void)x;
	(void)y;
	if (wheel == 4)
		fr->zoom *= 0.85;
	else if (wheel == 5)
		fr->zoom *= 1.15;
	ft_display(fr);
	return (0);
}
