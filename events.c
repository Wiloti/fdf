#include "fdf.h"

int		key_hook(int key, void *data)
{
	if (key == 0x35)
		exit(0);
}
