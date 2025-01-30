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
