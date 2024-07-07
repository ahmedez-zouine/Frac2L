/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:18:49 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/06 20:18:51 by aez-zoui         ###   ########.fr       */
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
	exit(EXIT_FAILURE);
}

void	ft_cleanup(t_fractol *fr)
{
	if (fr)
	{
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
			mlx_destroy_display(fr->mlx_connect);
			free(fr->mlx_connect);
		}
		free(fr);
	}
}
