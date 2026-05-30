#include <iostream>
#include <SDL3/SDL.h>

#include <app.hpp>
#include <render/render.hpp>
#include <gui/texts/text.hpp>
#include <states/game_states/menu_state.hpp>


Text_Handler Menu_State::text_handler;

Menu_State::Menu_State()
{
    printf( "Menu_State Init\n" );
    renderer_clear_color = COLOR::BLACK;

    // Assign text handler pointer to static handler
    TextHandler = &text_handler;
}

bool Menu_State::init_texts( Game::Context &ctx ) 
{
    SDL_Color text_color = getColor( COLOR::WHITE );
    if ( !text_handler.add_text( "Snake", text_color, Text_Anchor::CENTERX ) ) {
        return false;
    }
    Text *text = &text_handler.Texts[0];
    text->updateTextAnchor( ctx, text->anchor );

    text->rect.y = ctx.window_height * 0.20;
    return true;
}
