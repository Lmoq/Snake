#include <iostream>
#include <app.hpp>
#include <render/render.hpp>


void drawGrids( SDL_Renderer *renderer, int width, int height, int grid_size )
{
    int x1, x2, y1, y2;

    // Vertical lines, y values are constant
    y1 = 0;
    y2 = height;

    for ( x1 = grid_size; x1 < width; x1 += grid_size ) {
        x2 = x1;

        if ( !SDL_RenderLine( renderer, x1, y1, x2, y2 ) ) {
            SDL_Log( "Render failed : %s\n", SDL_GetError() );
        }
    }
    // Horizontal lines, x values are constant
    x1 = 0;
    x2 = width;

    for ( y1 = grid_size; y1 < height; y1 += grid_size ) {
        y2 = y1;
        if ( !SDL_RenderLine( renderer, x1, y1, x2, y2 ) ) {
            SDL_Log( "Render failed : %s\n", SDL_GetError() );
        }
    }
}

void changeRenderColor( Game::Context &ctx, COLOR color, Uint8 alpha )
{
    bool change_color = true;
    Uint8 r, g, b, a = alpha;

    switch ( color )
    {
        case COLOR::BLUE:
            r = 0x00, g = 0x00, b = 0xFF;
            //printf( "Chose black\n" );
            break;

        case COLOR::GREY:
            r = 0x80, g = 0x80, b = 0x80;
            break;

        case COLOR::RED:
            r = 0xFF, g = 0x00, b = 0x00;
            break;

        case COLOR::ORANGE:
            r = 0xFF, g = 0xA5, b = 0x00;
            break;

        case COLOR::PALE_GRAY:
            r = 0xB4, g = 0xB3, b = 0xC8;
            break;

        case COLOR::GREEN:
            r = 0x00, g = 0xFF, b = 0x00;
            break;

        case COLOR::WHITE:
            r = 0xFF, g = 0xFF, b = 0xFF;
            break;

        case COLOR::BLACK:
            r = 0x00, g = 0x00, b = 0x00;
            break;

        case COLOR::VIOLET:
            r = 0x7F, g = 0x00, b = 0xFF;
            break;

            // Custom Colors
        case COLOR::GRID_LINES:
            r = 0xB4, g = 0xB3, b = 0xC8, a = 0x64;
            break;

        default:
            change_color = false;
            break;
    }
    if ( !change_color ) return;

    if ( !SDL_SetRenderDrawColor( ctx.renderer, r, g, b, a ) ) {
        SDL_Log( "SetRenderDrawColor failed : %s\n", SDL_GetError() );
    }
}

void changeRenderColor( Game::Context &ctx, SDL_Color color )
{
    if ( !SDL_SetRenderDrawColor( ctx.renderer, color.r, color.g, color.b, color.a ) ) {
        SDL_Log( "SetRenderDrawColor failed : %s\n", SDL_GetError() );
    }
}
