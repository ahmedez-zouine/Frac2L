#include "fractol.h"

// [0..799] --> [-2.2]

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex result;
    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}

t_complex squire_complex(t_complex z)
{
    t_complex result;
    result.x = (z.x * z.x) - (z.y * z.y) -0.4;
    result.y = 2 * z.x * z.y + 0.6;
    // result.x = fabs(result.x);
    // result.y = fabs(result.y);
    return (result);
}