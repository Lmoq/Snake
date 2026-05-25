#ifndef __APP_H__
#define __APP_H__

#include <SDL3/SDL.h>

namespace Game 
{
	struct Context 
    {
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;
        
        const SDL_DisplayMode *displayMode = nullptr;

        int screen_width{};
        int screen_height{};

        int window_width{};
        int window_height{};

        SDL_Event event{};
        bool running = true;
	};
}

bool Init_Game( Game::Context &ctx );
bool Init_Display_Info( const SDL_DisplayMode *& display_mode );
void Quit_Game( Game::Context &ctx );

#endif