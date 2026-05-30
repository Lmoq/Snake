#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <SDL3/SDL.h>
#include <main.hpp>
#include <render/render.hpp>
#include <gui/texts/text.hpp>


namespace Game {
    struct Context;
};

class Game_State
{
    public:
        Text_Handler *TextHandler;

        COLOR renderer_clear_color = COLOR::BLACK;

        virtual void listen( Game::Context &ctx );
        virtual void update( Game::Context &ctx ) = 0;
        void render( Game::Context &ctx, COLOR clear_color = COLOR::BLACK )
        {
            // Reset board
            changeRenderColor( ctx, clear_color );
            SDL_RenderClear( ctx.renderer );

            changeRenderColor( ctx, COLOR::GRID_LINES );
            drawGrids( ctx.renderer, ctx.window_width, ctx.window_height, ENTITY_SIZE );

            drawTexts( ctx );
            SDL_RenderPresent( ctx.renderer );
        }
        void render( Game::Context &ctx, SDL_Color clear_color = { 0x00, 0x00, 0x00, 0x00 } )
        {
            // Reset board
            changeRenderColor( ctx, clear_color );
            SDL_RenderClear( ctx.renderer );

            changeRenderColor( ctx, COLOR::GRID_LINES );
            drawGrids( ctx.renderer, ctx.window_width, ctx.window_height, ENTITY_SIZE );

            drawTexts( ctx );
            SDL_RenderPresent( ctx.renderer );
        }
        void drawTexts( Game::Context &ctx )
        {
            for ( Text text : TextHandler->Texts ) {
                if ( !TTF_DrawRendererText( text.ttf_text, text.rect.x, text.rect.y ) ) {
                    SDL_Log( "RenderText failed : %s\n", SDL_GetError() );
                }
            }
        }
 

        /*void mouse_motion( Game::Context &ctx, Text_Handler *TextHandler = nullptr );
        void mouse_button( Game::Context &ctx, Text_Handler *TextHandler = nullptr );
        void key_button_down( Game::Context &ctx );*/
};


#endif