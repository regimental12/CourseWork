#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), m_postion(pParams->getX(), pParams->getY()), m_velocity(0, 0), m_accelaration(0,0)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();

	m_currentRow = 1;
	m_currentFrame = 1;
}

SDLGameObject::~SDLGameObject()
{
}

void SDLGameObject::draw()
{
	if (m_velocity.getX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_postion.getX(), (int)m_postion.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer() , SDL_FLIP_HORIZONTAL);
	}
	else
	{
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_postion.getX(), (int)m_postion.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
	}
}

void SDLGameObject::update()
{
	m_postion += m_accelaration;
	m_postion += m_velocity;
}

void SDLGameObject::clean()
{
}
