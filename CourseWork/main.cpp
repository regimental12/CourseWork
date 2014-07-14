#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	//init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		//if success
		g_pWindow = SDL_CreateWindow("Chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

		//if window success create renderer
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else
	{
		//sdl could not init
		return 1; 
	}

	// set window to black
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	//clear window to black
	SDL_RenderClear(g_pRenderer);

	//show window
	SDL_RenderPresent(g_pRenderer);

	//call delay
	SDL_Delay(5000);

	//clean up
	SDL_Quit();

	return 0;
}