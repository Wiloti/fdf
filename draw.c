#include "fdf.h"

int			pixel_put(int x, int y)
{
	int     bps;
	int     size_line;
	int     endian;
	int     *img_data;
	t_data   *d;

	if (x >= 0 && x < 1000 && y >= 0 && y < 1000)
	{
		d = get_data(NULL);
		img_data = (int *)mlx_get_data_addr(d->img_ptr, &bps, &size_line, &endian);
		img_data[y * size_line / 4 + x] = 0xFFFFFF;
	}
	return (0);
}
static int		drawhigh(int x1, int y1, int x2, int y2)
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	d;
	double	xi;

	dx = x2 - x1;
	dy = y2 - y1;
	y = y1;
	x = x1;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	while (y <= y2)
	{
		pixel_put(x, y);
		if (d > 0)
		{
			x = x + xi;
			d = d - 2*dy;
		}
		d = d + 2 * dx;
		y++;
	}
	return (0);
}

static	int		drawlow(int x1, int y1, int x2, int y2)
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	d;
	double	yi;

	dx = x2 - x1;
	dy = y2 - y1;
	y = y1;
	x = x1;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	while (x <= x2)
	{
		pixel_put(x, y);
		if (d > 0)
		{
			y = y + yi;
			d = d - 2*dx;
		}
		d = d + 2 * dy;
		x++;
	}
	return (0);
}

static void		drawline(int x1, int y1, int x2, int y2)
{
	if (abs(y2 - y1) < abs(x2 - x1))
	{
		if (x1 > x2)
			drawlow(x2, y2, x1, y1);
		else
			drawlow(x1, y1, x2, y2);
	}
	else
	{
		if (y1 > y2)
			drawhigh(x2, y2, x1, y1);
		else
			drawhigh(x1, y1, x2, y2);
	}
}

int		draw(t_data *d)
{
	int		x;
	int		y;

	y = 0;
	while (y < d->map.height)
	{
		x = 0;
		while (x < d->map.width)
		{
			pixel_put(x * 10, y * 10);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
	return (0);
}
