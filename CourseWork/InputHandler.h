#ifndef _InputHandler_
#define _InputHandler_

#include <vector>

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



private:
	InputHandler();
	~InputHandler(){};

	static InputHandler* s_pInstance;
	
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksIntialised;
};

typedef InputHandler TheInputHandler;

#endif

