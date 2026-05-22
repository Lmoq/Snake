#include <iostream>
#include <SDL3/SDL.h>
#include "app.hpp"


bool Init_Game()
{
	if ( !SDL_Init( SDL_INIT_VIDEO | SDL_INIT_EVENTS ) ) {
		return false;
	}
	return true;
}

void Quit_Game()
{
	SDL_Quit();
	
}