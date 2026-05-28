#ifndef __STATE_HANDLER_H__
#define __STATE_HANDLER_H__

#include <deque>
#include <memory>
#include <SDL3/SDL.h>
#include <states/game_states/game_state.hpp>


class GameStateHandler 
{
    private:
        // States
        static std::deque<std::unique_ptr<Game_State>> state_stack;

    public:
        enum StateType {
            Menu,
            Play,
            Pause
        };

        static void pushState( std::unique_ptr<Game_State> state ) {
            state_stack.push_back( std::move( state ) );
        }
        static void popState() {
            if ( !state_stack.empty() ) {
                state_stack.pop_back();
            }
        }
        static void switchState( std::unique_ptr<Game_State> state ) {
            popState();
            pushState( std::move( state ) );
        }
        static void listen( Game::Context &ctx ) {
            state_stack.back()->listen( ctx );
        }
        static void update( Game::Context &ctx ) {
            state_stack.back()->update( ctx );
        }
        static void render( Game::Context &ctx ) 
        {
            std::unique_ptr<Game_State> &state = state_stack.back();
            state->render( ctx, state->renderer_clear_color );
        }
};



#endif