#include "MenuState.h"


MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	//do stuff
}

void MenuState::render()
{
	//do stuff
}

bool MenuState::onEnter()
{
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	return true;
}