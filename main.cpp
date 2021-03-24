#include <SDL2/SDL.h>
#include <emscripten.h>

SDL_Window *window;
SDL_Renderer *renderer;

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

void main_tick()
{
    SDL_SetRenderDrawColor(renderer, 211, 211, 211, 255); // light grey
    SDL_RenderClear(renderer);  // fills screen with render color (light grey)

    SDL_Rect tileRect = {50, 50, 100, 100}; // creates a 100x100 rectangle with left corner at point 50, 50
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   // red
    SDL_RenderFillRect(renderer, &tileRect);
    
    SDL_RenderPresent(renderer);
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    emscripten_set_main_loop(main_tick, -1, 1);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}