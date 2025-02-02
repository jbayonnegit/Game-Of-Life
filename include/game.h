#ifndef GAME_H
# define GAME_H
# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 720
# define WIDTH 1280

typedef struct s_game
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	int				**map;
	int				**map_next;
}					t_game;

void	window_loading(t_game *game);
void	window_clear(t_game *game);

t_game	*ctx_init(void);
int		**map_init(void);
void	rand_map(int **map);
void	draw_grid(SDL_Renderer *renderer, int **map);

int		new_cel(int **map, int i, int j);
void 	new_map(int **map, int **map_next);
void	freegame(t_game *game);

void	run_game(t_game *game);
void	handle_input(t_game *game);

#endif