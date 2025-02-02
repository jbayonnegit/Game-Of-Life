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

void	freemap(int **map)
{
	int	i;

	i = 0;
	while ((i < ((HEIGHT / 10) + 1)) && map[i])
	{
		free(map[i]);
		i++;
	}
	if (map)
		free(map);
}

void	freegame(t_game *game)
{
	freemap(game->map);
	freemap(game->map_next);
}