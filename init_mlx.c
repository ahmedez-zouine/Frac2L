/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:17:16 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/06 20:17:18 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(t_fractol *fr)
{
	ft_cleanup(fr);
	exit(1);
}

void	ft_init_events(t_fractol *fr)
{
	mlx_key_hook(fr->mlx_window, ft_key_hook, fr);
	mlx_hook(fr->mlx_window, 2, KeyPressMask, ft_key_hook, fr);
	mlx_hook(fr->mlx_window, 17, StructureNotifyMask, ft_close_window, fr);
}

void	ft_mlxinit(t_fractol *fr)
{
	fr->mlx_connect = mlx_init();
	if (fr->mlx_connect == NULL)
		malloc_error(fr);
	fr->mlx_window = mlx_new_window(fr->mlx_connect, WIDTH, HEIGHT, fr->name);
	if (!fr->mlx_window)
		malloc_error(fr);
	fr->myimg->img_ptr = mlx_new_image(fr->mlx_connect, WIDTH, HEIGHT);
	if (fr->myimg->img_ptr == NULL)
		malloc_error(fr);
	fr->myimg->pixels_ptr = mlx_get_data_addr(fr->myimg->img_ptr,
			&fr->myimg->bpp, &fr->myimg->line_len, &fr->myimg->endian);
	if (fr->myimg->pixels_ptr == NULL)
		malloc_error(fr);
	ft_init_events(fr);
}
