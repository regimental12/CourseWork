#ifndef _GAMESTTEMACHINE_
#define _GAMESTATEMACHINE_

#include "GameState.h"
#include <vector>

class GameStateMachine
{
public:
	GameStateMachine();
	~GameStateMachine();

	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();

private:

	std::vector<GameState*> m_gameStates;

};

#endif

