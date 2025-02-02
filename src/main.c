#include "../include/game.h"


int	main(void)
{
	t_game		*game;

	game = ctx_init();
	if (!game)
		return (-1);
	window_loading(game);
	run_game(game);
	return (0);
}