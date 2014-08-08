#include "MenuButton.h"


MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()) : SDLGameObject(pParams), m_callback(*callback)
{
	m_currentFrame = MOUSEOUT;
}

MenuButton::~MenuButton()
{
}

void MenuButton::draw()
{
	SDLGameObject::draw(); // base class draw call
}

void MenuButton::update()
{
	/*Vector2D* pMousePos = TheInputHandler::Instance()->getMousePostion();

	if (pMousePos->getX() < (m_postion.getX() + m_width) &&
		pMousePos->getX() >  m_postion.getX() &&
		pMousePos->getY() < (m_postion.getY() + m_height) &&
		pMousePos->getY() >  m_postion.getY())
	{*/
		m_currentFrame = MOUSEOVER;

		if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
		{
			m_currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;
		}

		else if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSEOVER;
		}
	//}
	else
	{
		m_currentFrame = MOUSEOUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}
