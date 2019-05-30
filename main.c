#include "X.h"
#include "fdf.h"
#include <stdio.h>

/*void	debugmap(t_map	map)
{
	int i;
	int j;

	j = 0;
	printf("w=%d;h=%d\n", map.width, map.height);
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			printf("% 4d", map.tab[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}*/

t_data	*get_data(t_data *new)
{
	static	t_data	*d = NULL;

	if (new != NULL)
		d = new;
	return (d);
}

int		main(int argc, char **argv)
{
	t_data	d;

	if (argc != 2)
		return (0);
	d.map = parse(argv[1]);
	d.mlx_ptr = mlx_init();
	d.win_ptr = mlx_new_window(d.mlx_ptr, 1000, 1000, argv[1]);
	d.img_ptr = mlx_new_image(d.mlx_ptr, 1000, 1000);
	get_data(&d);
	mlx_hook(d.win_ptr, DestroyNotify, 0, exit_hook, &d);
	mlx_loop_hook(d.mlx_ptr, draw, &d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
