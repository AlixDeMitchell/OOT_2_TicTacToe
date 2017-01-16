#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

bool InitSDL();

int main( void )
{
	InitSDL();

	SDL_Quit();
	return 0;
}

bool InitSDL()
{
	if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;

		return false;
	}

	return true;
}