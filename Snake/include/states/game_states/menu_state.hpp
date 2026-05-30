#ifndef __MENU_STATE_H__
#define __MENU_STATE_H__

#include <states/game_states/game_state.hpp>

class Menu_State : public Game_State
{
    public:
        Menu_State::Menu_State();
        static Text_Handler text_handler;
        
        void update( Game::Context &ctx ) override {};
        bool Init_Texts();
};







// Typed in nvim
class Sample_bar {
    public:
        int bar;
};

// Typed in Visual Studio
class Sample_foo {
	public:
		int foo;
};




#endif
