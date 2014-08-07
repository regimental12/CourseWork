#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState()
{
}

PlayState::~PlayState()
{
}

void PlayState::update()
{
	//do stuff
}

void PlayState::render()
{
	//do stuff
}

bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}
