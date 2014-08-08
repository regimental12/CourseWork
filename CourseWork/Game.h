#ifndef _Game_
#define _Game_

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <iostream>
#include "InputHandler.h"
#include "GameState.h"
#include "PlayState.h"
#include "MenuState.h"
#include "GameStateMachine.h"

class Game
{
public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool init(const char* title , int xpos , int ypos , int width , int height , int flags);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running(){ return m_bRunning; }

	std::vector<GameObject*> m_gameObjects;

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	GameStateMachine* m_pGameStateMachine;

	GameStateMachine* getGameStateMachine() { return m_pGameStateMachine; }

private:
	Game(){};
	~Game(){}

	static Game* s_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	int m_currentFrame;

	
};

typedef Game TheGame;

#endif