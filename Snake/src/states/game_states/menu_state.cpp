#include <iostream>
#include <render/render.hpp>
#include <states/game_states/menu_state.hpp>
#include <gui/texts/text.hpp>


Text_Handler Menu_State::text_handler;

Menu_State::Menu_State()
{
	printf( "Menu_State Init\n" );
	renderer_clear_color = COLOR::BLACK;
}

bool Menu::Init_Texts()
{
    text_handler.add_text()
}
