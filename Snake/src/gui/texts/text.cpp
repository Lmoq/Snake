#include <gui/texts/text.hpp>
#include <app.hpp>


bool Text::updateWidth()
{
	if ( !TTF_GetTextSize( ttf_text, &rect.w, &rect.h ) ) {
		SDL_Log( "GetTextSize failed : %s\n", SDL_GetError() );
		return false;
	}
	return true;
}

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

void Text_Handler::add_text( std::string string, SDL_Color color, int xpos, int ypos )
{
	TTF_Text *ttf_text = TTF_CreateText( Text_Handler::text_engine, Text_Handler::font, string.c_str(), 0 );
	Text text;
	text.string = string;

	text.color = color;
	text.ttf_text = ttf_text;

	text.rect.x = xpos;
	text.rect.y = ypos;

	int w, h;
	if ( !TTF_GetTextSize( ttf_text, &w, &h ) ) {
		SDL_Log( "GetTextSize failed : %s\n", SDL_GetError() );
		return;
	}
	text.rect.w = w;
	text.rect.h = h;

	Text_Handler::Texts.push_back( text );
}