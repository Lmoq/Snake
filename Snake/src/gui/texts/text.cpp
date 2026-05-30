#include <app.hpp>
#include <gui/texts/text.hpp>


TTF_Font *Text_Handler::font = nullptr;
TTF_TextEngine *Text_Handler::text_engine = nullptr;

bool Text_Handler::Init_Font_Engine( Game::Context ctx, std::string font_path, float font_size )
{
    font = TTF_OpenFont( font_path.c_str(), font_size );
    if ( font == nullptr )
    {
        SDL_Log( "OpenFont failed : %s\n", SDL_GetError() );
        return false;
    }

    text_engine = TTF_CreateRendererTextEngine( ctx.renderer );
    if ( text_engine == nullptr )
    {
        SDL_Log( "CreateTextEngine failed : %s\n", SDL_GetError() );
        return false;
    }
    return true;
}

bool Text_Handler::add_text( std::string string, SDL_Color color, Text_Anchor anchor, int xpos, int ypos )
{
    TTF_Text *ttf_text = TTF_CreateText( Text_Handler::text_engine, Text_Handler::font, string.c_str(), 0 );

    if ( ttf_text == nullptr ) {
        SDL_Log( "CreateText failed[%s] : %s", string.c_str(), SDL_GetError() );
        return false;
    }
    Text text;
    text.string = string;

    text.anchor = anchor;
    text.color = color;

    text.rect.x = xpos;
    text.rect.y = ypos;

    text.ttf_text = ttf_text;

    int w, h;
    if ( !TTF_GetTextSize( ttf_text, &w, &h ) ) {
        SDL_Log( "GetTextSize failed : %s\n", SDL_GetError() );
        return false;
    }
    text.rect.w = w;
    text.rect.h = h;

    Text_Handler::Texts.push_back( text );
    return true;
}

void Text_Handler::Destroy_Texts()
{
    if ( !Texts.empty() ) 
    {
        for ( Text text : Texts ) {
            if ( text.ttf_text != nullptr ) 
            {
                SDL_Log( "Destroying text : %s\n", text.string.c_str() );
                TTF_DestroyText( text.ttf_text );
            }
        }
    }
}

bool Text::updateWidth()
{
    if ( !TTF_GetTextSize( ttf_text, &rect.w, &rect.h ) ) {
        SDL_Log( "GetTextSize failed : %s\n", SDL_GetError() );
        return false;
    }
    return true;
}

void Text::updateTextAnchor( Game::Context &ctx, Text_Anchor anchor )
{
    switch ( anchor )
    {
        case Text_Anchor::CENTERX:
            rect.x = ( ctx.window_width - rect.w ) / 2;
            break;

        case Text_Anchor::CENTERY:
            rect.y = ( ctx.window_height - rect.h ) / 2;
            break;

        default:
            throw std::exception( "NotImplementedError" );
            break;
    }
}