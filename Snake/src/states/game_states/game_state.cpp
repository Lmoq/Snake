#include <iostream>
#include <states/game_states/game_state.hpp>


void Game_State::listen( Game::Context &ctx )
{
    while ( SDL_PollEvent( &ctx.event ) )
    {
        switch ( ctx.event.type )
        {
            case SDL_EVENT_QUIT:
                ctx.running = false;
                break;
        }
    }
}

