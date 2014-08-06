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

	bool joysticksInitialised() const { return m_bJoysticksIntialised; }

	void reset();

	void clean();

	void update();

	bool isKeyDown(SDL_Scancode key) const;

	int getAxisX(int joy , int stick) const;
	int getAxisY(int joy , int stick) const;
	bool getButtonState(int joy, int buttonNumber) const;

	bool getMouseButtonState(int buttonNumber) const;
	Vector2D getMousePostion() const; 

	

private:
	InputHandler();
	~InputHandler();

	InputHandler(const InputHandler&);
	InputHandler& operator=(const InputHandler&);

	//handle keyboard events
	void onKeyDown();
	void onKeyUp();

	//handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	//handle joystick events
	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);

	const Uint8* m_keystates;

	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksIntialised;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	std::vector<std::vector<bool>> m_buttonStates;
	const int m_joystickDeadZone = 10000;

	std::vector<bool> m_mouseButtonStates;
	Vector2D m_mousePosition;

	static InputHandler* s_pInstance;
	
	
};

typedef InputHandler TheInputHandler;

#endif

