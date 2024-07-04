#include "fractol.h"




int in_frac(double rl, double im, t_fractol *fr)
{
    double r;
    double  i;
    int     it;
    double tmp;

    r = rl;
    i = im;
    it = 0;
    while (it < 50 && (r * r) + (i * i) <= 4.0)
    {
        if (ft_strcmp("julia", fr->name))
        {
            tmp = r * r - i * i + 0.6;
            i = 2 * r * i + 0.0; 
        }
        else
        {
            tmp = r * r - i * i + rl;
            i = 2 * r * i + im;
        }
        r = tmp;
        it++; 
    }
    return (it);
}

int ft_in_col(int x, int y, t_fractol *fr)
{
    double  r;
    double  im;
    int     it;

    r = map(x, -2.0, 2.0, 0, 800) * fr->zoom;
    im = map(y, 2.0, -2.0, 0, 800) * fr->zoom;
    it = in_frac(r, im, fr);
    if (it == 50)
        return (0x000000);
    return (map(it, 0xFFFFFF, 0xFF00FF, 0, 50));
}

void     ft_display(t_fractol *fr)
{
    int x;
    int y;
    int pix;

    fr->myimg->img_ptr = mlx_new_image(fr->mlx_connect, 800, 800);
    fr->myimg->pixels_ptr = mlx_get_data_addr(fr->myimg->img_ptr, &fr->myimg->bpp, &fr->myimg->line_len, &fr->myimg->endian);
    y = 0;
    while (y < 800)
    {
        x = 0;
        while (x < 800)
        {
            pix = ft_in_col(x, y, fr);
            *(int *) (fr->myimg->pixels_ptr + x * fr->myimg->bpp / 8 + y * fr->myimg->line_len) = pix;
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fr->mlx_connect, fr->mlx_window, fr->myimg->img_ptr, 0, 0);
}
