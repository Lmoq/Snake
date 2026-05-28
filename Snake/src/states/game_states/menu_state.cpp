#include <iostream>
#include <render/render.hpp>
#include <states/game_states/menu_state.hpp>

Menu_State::Menu_State()
{
	printf( "Menu_State Init\n" );
	renderer_clear_color = COLOR::BLACK;
}