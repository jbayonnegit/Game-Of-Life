#include "../include/game.h"

void	free_map_init(int **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		map[i] = 0;
		i--;
	}
	free(map);
	map = 0;
}