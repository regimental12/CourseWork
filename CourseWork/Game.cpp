#include "Game.h"


bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) // attempt SDL init
	{
		std::cout << "SDL init success\n";
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags); // attempt window init

		if (m_pWindow != 0) // window success
		{
			std::cout << "SDL window success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0); // attempt renderer init

			if (m_pRenderer != 0) // renderer success
			{
				std::cout << "Renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
			}
			else
			{
				std::cout << "Renderer init fail\n";
				return false;
			}
		}
		else
		{
			std::cout << "Window init fail\n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;
	}

	if (!theTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
	{
		return false;
	}

	std::cout << "Init success\n";
	m_bRunning = true; // start main loop


	m_gameObjects.push_back(new Player(new LoaderParams(100 , 100 , 128 , 82 , "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear renderer to colour;

	//loop through objects to draw them
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer); // draw to screen
}

void Game::clean()
{
	std::cout << "cleaning game\n";

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				m_bRunning = false;
				break;

			default:
				break;
		}
	}
}

void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

Game* Game::s_pInstance = 0;