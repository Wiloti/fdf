#include "fdf.h"
#include <stdio.h>

void	debugmap(t_map	map)
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
}
int		main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (0);
	map = parse(argv[1]);
	debugmap(map);
	return (0);
}
