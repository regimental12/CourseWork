#ifndef _Game_
#define _Game_

#include "SDL.h"
#include "SDL_image.h"

class Game
{
public:
	Game();
	~Game();

	bool init(const char* title , int xpos , int ypos , int width , int height , int flags);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running(){ return m_bRunning; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectanlge;

	bool m_bRunning;
};

#endif //end of Game def