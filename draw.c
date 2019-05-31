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

void	drawedges(t_map map, int i, int j)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	dh;

	dx = 30;
	dy = 50;
	dh = 4;
	x = i * dx + j * dx;
	y = j * dy - map.tab[j][i] * dh;
	if (i + 1 < map.width)
		drawline(x, y, ((i + 1) * dx + j * dx), j * dy - map.tab[j][i + 1] * dh);
	if (j + 1 < map.height)
		drawline(x, y, i  * dx + (j + 1) * dx, (j + 1) * dy - map.tab[j + 1][i] * dh);
	if (i + 1 < map.width && j + 1 < map.height)
		drawline(x, y, ((i + 1) * dx + (j + 1) * dx), (j + 1) * dy - map.tab[j + 1][i + 1] * dh);
}

int		draw(t_data *d)
{
	int		i;
	int		j;

	j = 0;
	while (j < d->map.height)
	{
		i = 0;
		while (i < d->map.width)
		{
			drawedges(d->map, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
	return (0);
}
