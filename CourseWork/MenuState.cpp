#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"


MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	if (m_menuObjects.empty() == false)
	{
		for (int i = 0; i < m_menuObjects.size(); i++)
		{
			if (m_menuObjects[i] != 0)
			{
				m_menuObjects[i]->update();
			}
		}
	}
	
}

void MenuState::render()
{
	if (m_menuObjects.empty() == true)
	{
		return;
	}
	for (int i = 0; i < m_menuObjects.size(); i++)
	{
		m_menuObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!theTextureManager::Instance()->load("assets/button.png" , "playbutton" , TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!theTextureManager::Instance()->load("assets/exit.png" , "exitbutton" , TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"), s_exitFromMenu);

	m_menuObjects.push_back(button1);
	m_menuObjects.push_back(button2);

	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_menuObjects.size(); i++)
	{
		m_menuObjects[i]->clean();
	}

	m_menuObjects.clear();
	theTextureManager::Instance()->clearFromTextureMap("playbutton");
	theTextureManager::Instance()->clearFromTextureMap("exitbutton");

	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getGameStateMachine()->changeState(new PlayState());
	std::cout << "Play button clicked\n";
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
	std::cout << "Exit button clicked\n";
}