#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	SDLGameObject::draw();

}

void Enemy::update()
{
	m_postion.setX(m_postion.getX() + 1);
	m_postion.setY(m_postion.getY() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}


void Enemy::clean()
{
}