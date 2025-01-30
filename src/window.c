#include "../include/game.h"

void	window_loading(t_game *game)
{
	if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stderr, "SDL INIT ERROR : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	game->window = SDL_CreateWindow("Le jeu de la vie", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	if (!game->window)
	{
		fprintf(stderr, "SDL WIMDOW ERROR : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	game->render = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
	if (!game->window)
	{	
		fprintf(stderr, "SDL RENDER ERROR : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void	window_clear(t_game *game)
{
	SDL_DestroyRenderer(game->render);
	SDL_DestroyWindow(game->window);
	SDL_Quit();
}
