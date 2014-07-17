#include "Game.h"

int main(int argc, char* args[])
{
	std::cout << "init game attempt...\n";
	if (TheGame::Instance()->init("chapter 1" , 100 , 100 , 640 , 480 , false))
	{
		std::cout << "game init success\n";
		while (TheGame::Instance()->running())
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			SDL_Delay(10);
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