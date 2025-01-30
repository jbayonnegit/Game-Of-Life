#include "../include/game.h"

int	main(void)
{
	t_game	*game;
    SDL_Rect *cel;

	cel = malloc(sizeof(SDL_Rect));
    cel->x = 500;
    cel->y = 200;
    cel->w = 20;
    cel->h = 20;
	game = ctx_init();
	window_loading(game);
	SDL_SetRenderDrawColor(game->render, 0, 0, 0, 255);
	SDL_RenderClear(game->render);
	
    // Main loop
    int running = 1;
    SDL_Event event;
    
    while (running) {
        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Clear screen with black color
        SDL_SetRenderDrawColor(game->render, 0, 0, 0, 255);
        SDL_RenderClear(game->render);

        // Set draw color to red and draw a filled rectangle
        SDL_SetRenderDrawColor(game->render, 255, 255, 255, 255);
        SDL_Rect rect = { 200, 150, 10, 10 }; // x, y, width, height
        SDL_RenderFillRect(game->render, &rect);

        // Present the renderer (update screen)
        SDL_RenderPresent(game->render);

        SDL_Delay(16); // Simulate ~60 FPS
    }

    // Cleanup
    SDL_DestroyRenderer(game->render);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
    return 0;

	free(game);
	return (0);
}