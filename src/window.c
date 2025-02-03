#include "../include/game.h"

void	window_loading(t_game *game)
{
	if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stderr, "SDL INIT ERROR : %s", SDL_GetError());
		freegame(game);
		exit(EXIT_FAILURE);
	}
	game->window = SDL_CreateWindow("Le jeu de la vie", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!game->window)
	{
		fprintf(stderr, "SDL WIMDOW ERROR : %s", SDL_GetError());
		freegame(game);
		exit(EXIT_FAILURE);
	}
	game->render = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
	if (!game->render)
	{	
		fprintf(stderr, "SDL RENDER ERROR : %s", SDL_GetError());
		freegame(game);
		exit(EXIT_FAILURE);
	}
}

void	draw_grid(SDL_Renderer *renderer, int **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 10)
	{
		j = 0;
		while (j < WIDTH / 10)
		{
			SDL_Rect cell =  {j * 10, i * 10, 10, 10};
            SDL_SetRenderDrawColor(renderer, map[i][j] ? 255 : 0, map[i][j] ? 255 : 0,map[i][j] ? 255 : 0, 255);
            SDL_RenderFillRect(renderer, &cell);
            SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
            SDL_RenderDrawRect(renderer, &cell);
			j++;
		}
		i++;
	}
}

void	window_clear(t_game *game)
{
	freegame(game);
	SDL_DestroyRenderer(game->render);
	SDL_DestroyWindow(game->window);
	free(game);
	SDL_Quit();
}
