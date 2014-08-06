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
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->joysticksInitialised())
	{
		//left stick 
		if (TheInputHandler::Instance()->getAxisX(0, 1) > 0 || TheInputHandler::Instance()->getAxisX(0, 1) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->getAxisX(0, 1));
		}

		if (TheInputHandler::Instance()->getAxisY(0, 1)> 0 || TheInputHandler::Instance()->getAxisY(0, 1) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->getAxisY(0, 1));
		}

		//right stick
		if (TheInputHandler::Instance()->getAxisX(0, 2)> 0 || TheInputHandler::Instance()->getAxisX(0, 2) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->getAxisX(0, 2));
		}

		if (TheInputHandler::Instance()->getAxisY(0, 2)> 0 || TheInputHandler::Instance()->getAxisY(0, 2) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->getAxisY(0, 2));
		}


		if (TheInputHandler::Instance()->getButtonState(0, 3))
		{
			m_velocity.setX(1);
		}
	}

		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_velocity.setY(1);
		}

		if (TheInputHandler::Instance()->getMouseButtonState(RIGHT))
		{
			m_velocity.setY(-1);
		}

		Vector2D vec = TheInputHandler::Instance()->getMousePostion();

		m_velocity = (vec - m_postion) / 100;

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		{
			m_velocity.setX(2);
		}

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		{
			m_velocity.setX(-2);
		}

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
		{
			m_velocity.setY(-2);
		}

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
		{
			m_velocity.setY(2);
		}
}