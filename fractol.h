/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:13:57 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/06 20:16:00 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 800
# define WIDTH 800

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connect;
	void	*mlx_window;
	t_img	*myimg;
	int		iteration;
	double	zoom;
	double	real;
	double	imag;
	double	shift_x;
	double	shift_y;

}			t_fractol;

void		ft_mlxinit(t_fractol *fr);
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(int nb, char *str);
int			ft_zoom(int wheel, int x, int y, t_fractol *fr);
void		ft_display(t_fractol *fr);
void		malloc_error(t_fractol *fr);
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
int			ft_close_window(t_fractol *fr);
int			ft_key_hook(int keycode, t_fractol *fr);
void		ft_cleanup(t_fractol *fract);
void		calc_julia(double *r, double *i, t_fractol *fr);
double		ft_atof(char *str);

#endif
