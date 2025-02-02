#include "../include/game.h"


int	new_cel(int **map, int i, int j)
{
	int	e;
	int	s;

	s = 0;
	e = map[i][j];
	if (j + 1 < WIDTH / 10)
		s = map[i][j + 1];
	if (j - 1 >= 0)
		s = s + map[i][j - 1];
	if (i + 1 < HEIGHT / 10)
		s = s + map[i + 1][j];
	if (i - 1 >= 0)
		s = s + map[i - 1][j];
	if ((i + 1 < HEIGHT / 10) && (j + 1 < WIDTH / 10))
		s = s + map[i + 1][j + 1];
	if ((i - 1 >= 0) && (j - 1 >= 0))
		s = s + map[i - 1][j - 1];
	if ((i + 1 < HEIGHT / 10) && (j - 1 >= 0))
		s = s + map[i + 1][j - 1];
	if ((i - 1 >= 0) && (j + 1 < WIDTH / 10))
		s = s + map[i - 1][j + 1];
	if (e == 0)
	{
		if (s == 3)
			return (1);
		else
			return (0);
	}
	if (e == 1)
	{
		if (s == 3 || s == 2)
			return (1);
		else
			return (0);
	}
	return (0);
} 

void new_map(int **map, int **map_next)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 10)
	{
		j = 0;
		while (j < WIDTH / 10)
		{
			map_next[i][j] = new_cel(map, i ,j); 
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_game		*game;
	int			**map;
	int			**tmp;
	int			**map_next;
	int			i;

	game = ctx_init();
	if (!game)
		return (-1);
	window_loading(game);
	map = map_init();
	map_next = map_init();
	if (!map || !map_next)
		return (-1);
	rand_map(map);
	i = 0;
	tmp = map;
	while (1)
	{
		if (i == 100)
			i = 0;
		SDL_RenderClear(game->render);
        draw_grid(game->render, tmp);
        SDL_RenderPresent(game->render);
        SDL_Delay(200);
		if (i % 2 == 0)
		{
			new_map(map, map_next);
			tmp = map_next;
		}
		else
		{
			new_map(map_next, map);
			tmp = map;
		}
		i++;
	}
	return (0);
}