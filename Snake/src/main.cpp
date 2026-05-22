#include <iostream>
#include <SDL3/SDL.h>
#include "main.hpp"
#include "app.hpp"


int main( int argc, char** argv )
{
	if ( !Init_Game() ) {
		Quit_Game();
		printf( "Game exited early\n" );
		return 0;
	}

	Quit_Game();
	printf( "Game Quit\n" );
	return 0;
}