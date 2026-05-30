#include <iostream>
#include <cassert>
#include <SDL3/SDL.h>

#include <main.hpp>
#include <app.hpp>
#include <render/render.hpp>
#include <states/game_states/state_handler.hpp>
#include <states/game_states/menu_state.hpp>


std::deque<std::unique_ptr<Game_State>> GameStateHandler::state_stack;

int main( int argc, char** argv )
{
    Game::Context ctx;

    if ( !Init_Game( ctx ) )
    {
        Quit_Game( ctx );
        printf( "Game exited early\n" );
        return 0;
    }
    GameStateHandler::switchState( std::make_unique<Menu_State>() );
    assert( ( !GameStateHandler::state_stack.empty() ) 
        && "GameStateHandler::state_stack should not be empty before running main loop"
    );

    while ( ctx.running )
    {
        ctx.timer.calc_DeltaTime();

        GameStateHandler::listen( ctx );
        GameStateHandler::render( ctx );

        ctx.timer.frameLimiter();
    }

    Quit_Game( ctx );
    printf( "Game Quit\n" );
    return 0;
}