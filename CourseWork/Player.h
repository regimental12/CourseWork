#ifndef _Player_
#define _Player_

#include "SDLGameObject.h"
#include "GameObject.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	~Player();
	void draw();
	void update();
	void clean();
};

#endif
