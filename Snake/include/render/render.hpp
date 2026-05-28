#ifndef __RENDER_H__
#define __RENDER_H__

#include <SDL3/SDL.h>

namespace Game {
	struct Context;
}


enum class COLOR {
	BLUE,
	GREY,
	RED,
	ORANGE,
	PALE_GRAY,
	GREEN,
	WHITE,
	BLACK,
	VIOLET,
	// Custom colors
	GRID_LINES
};


void drawGrids( SDL_Renderer *renderer, int width, int height, int grid_size );
void changeRenderColor( Game::Context &ctx, COLOR color, Uint8 alpha = 255 );
void changeRenderColor( Game::Context &ctx, SDL_Color color );
SDL_Color getColor( COLOR color, Uint8 alpha = 255 );


#endif