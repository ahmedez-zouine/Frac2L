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

# include <X11/X.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
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

# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000 // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF // RGB(0, 0, 255)

# define MAGENTA_BURST 0xFF00FF // A vibrant magenta
# define LIME_SHOCK 0xCCFF00 // A blinding lime
# define NEON_ORANGE 0xFF6600 // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066 // A deep purple
# define AQUA_DREAM 0x33CCCC // A bright turquoise
# define HOT_PINK 0xFF66B2 // As the name suggests!
# define ELECTRIC_BLUE 0x0066FF // A radiant blue
# define LAVA_RED 0xFF3300 // A bright, molten red
#endif
