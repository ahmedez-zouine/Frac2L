/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:19:31 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/23 20:55:00 by aez-zoui         ###   ########.fr       */
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
	if (keycode == KEY_ESC || keycode == KEY_ESC_MAC)
		ft_close_window(fr);
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_MAC
		|| keycode == KEY_PLUS_REG)
		fr->iteration++;
	else if (keycode == KEY_MINUS || keycode == KEY_MINUS_MAC
		|| keycode == KEY_MINUS_REG)
	{
		if (fr->iteration > 1)
			fr->iteration--;
	}
	else if (keycode == KEY_LEFT || keycode == KEY_LEFT_MAC)
		fr->shift_x += 0.2;
	else if (keycode == KEY_UP || keycode == KEY_UP_MAC)
		fr->shift_y -= 0.2;
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_MAC)
		fr->shift_x -= 0.2;
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_MAC)
		fr->shift_y += 0.2;
	ft_display(fr);
	return (0);
}

int	ft_zoom(int wheel, int x, int y, t_fractol *fr)
{
	(void)x;
	(void)y;
	if (wheel == MOUSE_WHEEL_UP)
		fr->zoom *= 0.85;
	else if (wheel == MOUSE_WHEEL_DOWN)
		fr->zoom *= 1.15;
	ft_display(fr);
	return (0);
}
