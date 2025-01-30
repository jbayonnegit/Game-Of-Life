#ifndef GAME_H
# define GAME_H
# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 720
# define WIDTH 1920

typedef struct s_game
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	
}					t_game;

void	window_loading(t_game *game);
void	window_clear(t_game *game);

t_game	*ctx_init(void);
int		**map_init(void);

#endif