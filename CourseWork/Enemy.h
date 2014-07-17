#ifndef _Enemy_
#define _Enemy_

#include "SDLGameObject.h"
#include "GameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	~Enemy();
	void draw();
	void update();
	void clean();
};

#endif
