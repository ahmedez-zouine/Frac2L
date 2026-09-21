/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:13:57 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/07/23 20:55:00 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

/* Screen Dimension Constants */
# define WIDTH 800
# define HEIGHT 800

/* Linux X11 Keycodes */
# define KEY_ESC 65307
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_PLUS_REG 61
# define KEY_MINUS_REG 45
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

/* macOS Keycodes */
# define KEY_ESC_MAC 53
# define KEY_PLUS_MAC 69
# define KEY_MINUS_MAC 78
# define KEY_LEFT_MAC 123
# define KEY_RIGHT_MAC 124
# define KEY_DOWN_MAC 125
# define KEY_UP_MAC 126

/* Mouse Buttons */
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

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

/* Initialization & Cleanup */
void		ft_mlxinit(t_fractol *fr);
void		ft_init_events(t_fractol *fr);
void		ft_cleanup(t_fractol *fract);
void		malloc_error(t_fractol *fr);

/* Event Hooks */
int			ft_close_window(t_fractol *fr);
int			ft_key_hook(int keycode, t_fractol *fr);
int			ft_zoom(int wheel, int x, int y, t_fractol *fr);

/* Rendering & Formulas */
void		ft_display(t_fractol *fr);
int			in_frac(double rl, double im, t_fractol *fr);
void		calc_mandelbrot(double *r, double *i, double rl, double im);
void		calc_tricorn(double *r, double *i, double rl, double im);
void		calc_julia(double *r, double *i, t_fractol *fr);

/* Mathematics & Parsing */
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
double		ft_atof(char *str);
int			ft_isdigit(char c);

/* Utilities & Diagnostics */
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(int fd, char *str);
void		print_help(void);

#endif
