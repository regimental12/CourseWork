#ifndef _SDLGameObject_
#define _SDLGameObject_

#include "GameObject.h"
#include <SDL.h>
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	~SDLGameObject();

	virtual void draw();
	virtual void update();
	virtual void clean();

protected:
	Vector2D m_postion;
	Vector2D m_velocity;
	Vector2D m_accelaration;
	 
	int m_height;
	int m_width;

	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;
};

#endif

