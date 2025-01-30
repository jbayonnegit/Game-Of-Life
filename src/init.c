#include "../include/game.h"

t_game	*ctx_init(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		perror("CTX INIT FAILED");
		exit(EXIT_FAILURE) ;
	}
	return (game);
}

void	rand_map(int **map)
{
	int i;
	int j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			map[i][j] = rand() % 10;
			j++;
		}
		i++;
	}
}

int	**map_init(void)    
{
	int	**map;
	int	i;

	map = malloc(sizeof(int *) * HEIGHT + 1);
	if (!map)
	{
		perror("MALLOC FAILED");
		exit(EXIT_FAILURE);
	}
	map[HEIGHT] = 0;	
	for (i = 0; i < HEIGHT ;i++)
	{
		map[i] = malloc(sizeof(int) * WIDTH + 1);
		if (!map[i])
		{
			perror("MALLOC FAILED");
			exit(EXIT_FAILURE);
		}
	}
	rand_map(map);
	return (map);
}