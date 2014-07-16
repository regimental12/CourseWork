#include "Game.h"

Game* g_game = 0;

int main(int argc, char* args[])
{
	g_game = new Game();

	g_game->init("chap 1" , 100 , 100 , 640 , 480 , 0);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();

		SDL_Delay(10); // cap frame rate
	}
	g_game->clean();

	return 0;
}