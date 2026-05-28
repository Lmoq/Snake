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