#include "Game.h"
#include <iostream>

Game::Game()
{

}

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

	std::cout << "Init success\n";
	m_bRunning = true; // start main loop

	if (!theTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
	{
		return false;
	}

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear renderer to colour;

	theTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

	theTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

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
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}