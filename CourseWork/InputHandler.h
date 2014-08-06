#ifndef _InputHandler_
#define _InputHandler_

#include <iostream>
#include <vector>
#include <SDL.h>
#include "Game.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2,
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void initialiseJoysticks();

	bool joysticksInitialised() { return m_bJoysticksIntialised; }

	void clean();

	void update();

	int xvalue(int joy , int stick);
	int yvalue(int joy , int stick);

	bool getButtonState(int joy, int buttonNumber);
	bool getMouseButtonState(int buttonNumber);

	Vector2D getMousePostion(); 

private:
	InputHandler();
	~InputHandler();

	static InputHandler* s_pInstance;
	
	std::vector<SDL_Joystick*> m_joysticks;

	bool m_bJoysticksIntialised;

	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;

	std::vector<std::vector<bool>> m_buttonStates;

	std::vector<bool> m_mouseButtonStates;

	const int m_joystickDeadZone = 10000;

	Vector2D m_mousePosition;

	
};

typedef InputHandler TheInputHandler;

#endif

