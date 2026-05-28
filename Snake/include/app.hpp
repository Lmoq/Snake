#ifndef __APP_H__
#define __APP_H__

#include <SDL3/SDL.h>
#include <timer.hpp>


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

        bool running = true;
        SDL_Event event{};
        Timer timer{ Timer::Scale::Nano };
	};
}

bool Init_Game( Game::Context &ctx );
bool Init_Display_Info( const SDL_DisplayMode *& display_mode );
void Quit_Game( Game::Context &ctx );

#endif