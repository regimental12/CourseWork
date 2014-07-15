#ifndef _TextureManager_
#define _TextureManager_

#include "SDL.h"
#include "SDL_image.h"
#include <iostream> 
#include <map>

class TextureManager
{
public:
	bool load(std::string filename, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow,
		           int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);

	std::map<std::string, SDL_Texture*>m_textureMap;

private:
	// more stuff?

};

#endif 