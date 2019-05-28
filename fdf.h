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

typedef	struct			s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		color;
}						t_data;

t_map	parse(char *filename);

#endif
