#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	void update();
	void clean();
	void draw(SDL_Renderer* pRenderer);
	void load(int x, int y, int width, int height, std::string textureID);

protected:
	std::string m_textureID;

	int m_x;
	int m_y;
	int m_currentFrame;
	int m_currentRow;
	int m_width;
	int m_height;	
};
