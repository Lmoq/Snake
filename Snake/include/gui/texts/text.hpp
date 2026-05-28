#ifndef __TEXT_H__
#define __TEXT_H__

#include <string>
#include <functional>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

class Text 
{
	public:
        std::string text;
        SDL_Rect rect;

        SDL_Color color{};
        SDL_Color color_on_hover{};

        bool hovered = false;
        bool hoverable = false;

        std::function<void()> On_Click = nullptr;
        TTF_Text *ttf_text = nullptr;

		bool updateWidth();
};

namespace Game {
    struct Context;
};

class Text_Handler 
{
    public:
        TTF_Font *font;
        TTF_TextEngine *text_engine;

        std::vector<Text> Texts;

        void add_text( std::string text, SDL_Color color, int xpos=0, int ypos=0 );
        bool Init_Font_Engine( Game::Context ctx, std::string font_path, float font_size );
};


#endif
