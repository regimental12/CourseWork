#ifndef _MENUBUTTON_
#define _MENUBUTTON_

#include "SDLGameObject.h"
#include "InputHandler.h"

class MenuButton : public SDLGameObject
{
public:
	MenuButton(const LoaderParams* pParams , void (*callback)());
	~MenuButton();

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	enum button_state
	{
		MOUSEOUT = 0,
		MOUSEOVER = 1,
		CLICKED = 2
	};

	void(*m_callback)();
	bool m_bReleased;
};

#endif

