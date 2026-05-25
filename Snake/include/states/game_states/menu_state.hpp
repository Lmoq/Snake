#ifndef __MENU_STATE_H__
#define __MENU_STATE_H__

#include <states/game_states/game_state.hpp>

class Menu_State : public Game_State
{
	public:
		Menu_State::Menu_State();
		
		void update( Game::Context &ctx ) override {};
};


#endif