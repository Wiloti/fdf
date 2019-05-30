#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
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
	t_map	map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}						t_data;

t_map	parse(char *filename);
int		draw(t_data *d);
int		pixel_put(int x, int y);
t_data	*get_data(t_data * new);
int     exit_hook(int key, void *data);

#endif
