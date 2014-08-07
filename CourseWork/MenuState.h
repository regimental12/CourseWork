#ifndef _MENUSTATE_
#define _MENUSTATE_

#include "GameState.h"
#include "GameObject.h"
#include <vector>
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"

class MenuState : public GameState
{
public:
	MenuState();
	~MenuState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }
	std::vector<GameObject*> m_GameObjects;

private:

	static const std::string s_menuID;
	static void s_menuToPlay();
	static void s_exitFromMenu();
};

#endif