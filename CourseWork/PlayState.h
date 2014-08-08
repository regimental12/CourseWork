#ifndef _PLAYSTATE_
#define _PLAYSTATE_

#include <vector>
#include "GameState.h"
#include "GameObject.h"


class GameObject;

class PlayState : public GameState
{
public:
	PlayState();
	~PlayState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }

private:

	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
};

#endif