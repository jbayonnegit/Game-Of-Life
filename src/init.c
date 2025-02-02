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
	while (i < HEIGHT / 10)
	{
		j = 0;
		while (j < WIDTH / 10)
		{
			map[i][j] = rand() % 10;
			if (map[i][j] < 5)
				map[i][j] = 0;
			else	
				map[i][j] = 1;
			j++;
		}
		i++;
	}
}

int	**map_init(void)    
{
	int	**map;
	int	i;

	map = malloc(sizeof(int *) * ((HEIGHT / 10) + 1));
	if (!map)
	{
		perror("MALLOC FAILED");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < HEIGHT / 10 ;i++)
	{
		map[i] = malloc(sizeof(int) * ((WIDTH / 10) + 1));
		if (!map[i])
		{
			perror("MALLOC FAILED");
			exit(EXIT_FAILURE);
		}
	}
	map[HEIGHT / 10] = 0;	
	return (map);
}