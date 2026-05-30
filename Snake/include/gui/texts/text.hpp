#ifndef __TEXT_H__
#define __TEXT_H__

#include <string>
#include <functional>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>


enum class Text_Anchor {
    CENTERX,
    CENTERY,
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
    TOPLEFT,
    TOPRIGHT,
    BOTTOMLEFT,
    BOTTOMRIGHT
};

class Text
{
    public:
        std::string string;
        Text_Anchor anchor;

        SDL_Rect rect;

        SDL_Color color{};
        SDL_Color color_on_hover{};

        bool hovered = false;
        bool hoverable = false;

        std::function<void()> On_Click = nullptr;
        TTF_Text *ttf_text = nullptr;

        bool updateWidth();
        void updateTextAnchor( Game::Context &ctx, Text_Anchor anchor );
};

namespace Game {
    struct Context;
};

class Text_Handler
{
    public:
        static TTF_Font *font;
        static TTF_TextEngine *text_engine;

        std::vector<Text> Texts;

        bool add_text( std::string string, SDL_Color color, Text_Anchor anchor = Text_Anchor::CENTERX, int xpos = 0, int ypos = 0 );
        void Destroy_Texts();
        static bool Init_Font_Engine( Game::Context ctx, std::string font_path, float font_size );
};


#endif
