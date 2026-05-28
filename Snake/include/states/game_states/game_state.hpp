#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <SDL3/SDL.h>
#include <app.hpp>
#include <render/render.hpp>
#include <gui/texts/text.hpp>


class Game_State
{
    public:
        Text_Handler TextHandler;

        COLOR renderer_clear_color = COLOR::BLACK;

        virtual void listen( Game::Context &ctx );
        virtual void update( Game::Context &ctx ) = 0;
        virtual void render( Game::Context &ctx, COLOR clear_color = COLOR::BLACK ) 
        {
            changeRenderColor( ctx, clear_color );
            SDL_RenderClear( ctx.renderer );
            SDL_RenderPresent( ctx.renderer ); 
        }
        virtual void render( Game::Context &ctx, SDL_Color clear_color = { 0x00, 0x00, 0x00, 0x00 } ) 
        {
            changeRenderColor( ctx, clear_color );
            SDL_RenderClear( ctx.renderer );
            SDL_RenderPresent( ctx.renderer );
        }

        /*void mouse_motion( Game::Context &ctx, Text_Handler *TextHandler = nullptr );
        void mouse_button( Game::Context &ctx, Text_Handler *TextHandler = nullptr );
        void key_button_down( Game::Context &ctx );*/
};


#endif