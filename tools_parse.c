#include "fdf.h"

int		count_word(char *str)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strchr(" \t0123456789+-", str[i]))
			exit (0);
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '+' || str[i] == '-' || ft_isdigit((int)str[i]))
		{
			while (str[i] == '+' || str[i] == '-' || ft_isdigit((int)str[i]))
				i++;
			j++;
		}
		if (str[i] == ',')
		{
			i++;
			while (str[i] != ' ' && str[i] != '\t' && str[i])
				i++;
		}
	}
	return (j);
}

int		**intdjoin(int **tab, size_t size, int nb_word)
{
	int		**tab2;

	if (!(tab2 = (int **)malloc(sizeof(int *) * (size + 1))))
		return (NULL);
	if (!(tab2[size] = (int *)malloc(sizeof(int) * nb_word)))
		return (NULL);
	if (tab != NULL)
	{
		ft_memcpy(tab2, tab, size * sizeof(int *));
		free(tab);
	}
	return (tab2);
}

t_map	parse(char	*filename)
{
	t_map	map;
	int		fd;
	int		i;
	int		n;
	char	*line;

	fd = open(filename, O_RDONLY);
	map.width = -1;
	map.height = 0;
	map.tab = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (map.width == -1)
			map.width = count_word(line);
		else if (map.width != count_word(line))
			exit (0);
		map.tab = intdjoin(map.tab, map.height, map.width);
		i = 0;
		n = 0;
		while (n < map.width)
		{
			if (!ft_strchr(" \t0123456789+-", line[i]))
				exit (0);
			while (line[i] == ' ' ||  line[i] == '\t')
				i++;
			if (line[i] == '+'|| line[i] == '-' || ft_isdigit((int)line[i]))
			{
				map.tab[map.height][n++] = ft_atoi(line + i);
				while (line[i] == '+' || line[i] == '-' || ft_isdigit((int)line[i]))
					i++;
			}
			if (line[i] == ',')
			{
				i++;
				while (line[i] != ' ' && line[i] != '\t' && line[i])
					i++;
			}
		}
		map.height++;
		free(line);
	}
	return (map);
}
