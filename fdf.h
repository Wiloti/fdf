#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
#include <string.h>
#include <fcntl.h>

typedef	struct			s_map
{
	int	**tab;
	int	height;
	int	width;
}						t_map;

t_map	parse(char *filename);

#endif
