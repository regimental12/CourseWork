#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
	Uint32 frameStart , frameTime;

	std::cout << "init game attempt...\n";
	if (TheGame::Instance()->init("chapter 1" , 100 , 100 , 640 , 480 , false))
	{
		std::cout << "game init success\n";
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cout << "freak out cause - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << " game shut down...\n";
	TheGame::Instance()->clean();

	return 0;
}