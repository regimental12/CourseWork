#include "Player.h"


Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

Player::~Player()
{
}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_postion.setX(m_postion.getX() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{
}
