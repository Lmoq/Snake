#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <app.hpp>
#include <gui/texts/text.hpp>
#include <states/game_states/menu_state.hpp>


bool Init_Game( Game::Context &ctx )
{
    if ( !SDL_Init( SDL_INIT_VIDEO | SDL_INIT_EVENTS ) ) {
        SDL_Log( "SDL Init failed : %s\n", SDL_GetError() );
        return false;
    }

    if ( !TTF_Init() ) {
        SDL_Log( "TTF Init failed : %s\n", SDL_GetError() );
        return false;
    }

    if ( !Init_Display_Info( ctx.displayMode ) ) {
        SDL_Log( "Init Display Info failed\n" );
        return false;
    }

    // Set Display Info
    ctx.screen_width = ctx.displayMode->w;
    ctx.screen_height = ctx.displayMode->h;

    int window_width = ctx.screen_width * 0.70;
    int window_height = ctx.screen_height * 0.70;

    if ( !SDL_CreateWindowAndRenderer(
        "SampleWindow",
        window_width,
        window_height, 0,
        &ctx.window,
        &ctx.renderer ) )
    {
        SDL_Log( "CreateWindow and Renderer failed : %s\n", SDL_GetError() );
        return false;
    }

    if ( !SDL_GetWindowSizeInPixels( ctx.window, &ctx.window_width, &ctx.window_height ) ) {
        SDL_Log( "GetWindowSize failed : %s\n", SDL_GetError() );
        return false;
    }
    fixWindowSizeOffset( ctx );


    if ( !SDL_SetRenderDrawBlendMode( ctx.renderer, SDL_BLENDMODE_BLEND ) ) {
        SDL_Log( "SetRenderDrawBlendMode Failed : %s\n", SDL_GetError() );
        return false;
    }

    // Custom classes Inits
    // Set frame rate
    ctx.timer.init( ctx.displayMode->refresh_rate );

    // Init Game States Text_Handlers
    if ( !Text_Handler::Init_Font_Engine( ctx, "C:/Windows/Fonts/Arial.ttf", 24 ) ) {
        return false;
    }
    if ( !Menu_State::init_texts( ctx ) ) {
        return false;
    }
    
    return true;
}

bool Init_Display_Info( const SDL_DisplayMode *& display_mode )
{
    int num_displays;
    SDL_DisplayID *displays = SDL_GetDisplays( &num_displays );

    if ( displays == nullptr )
    {
        SDL_Log( "Failed to get displays : %s", SDL_GetError() );
        return false;
    }

    SDL_Log( "Found displays : " );
    for ( int i = 0; i < num_displays; i++ ) {
        SDL_Log( "[%d]", *( displays + i ) );
    }

    SDL_DisplayID display_id;
    if ( num_displays < 2 ) {
        display_id = *displays;
    }
    else {
        SDL_Log( "Number of %d displays were detected\n", num_displays );
        SDL_free( displays );
        return false;
    }
    SDL_free( displays );

    display_mode = SDL_GetDesktopDisplayMode( display_id );
    if ( display_mode == nullptr )
    {
        std::cout << "Failed to retrieve display info : " << SDL_GetError() << '\n';
        SDL_Quit();
        return false;
    }
    return true;
}



void Quit_Game( Game::Context &ctx )
{
    // TTF
    Menu_State::text_handler.Destroy_Texts();
    // Other states -------- Destroy Texts()

    if ( Text_Handler::font != nullptr ) {
        TTF_CloseFont( Text_Handler::font );
        SDL_Log( "Closed Font\n" );
    }

    if ( Text_Handler::text_engine != nullptr ) {
        TTF_DestroyRendererTextEngine( Text_Handler::text_engine );
        SDL_Log( "Destroy Text Engine\n" );
    }

    if ( int ttf_quit = TTF_WasInit(); ttf_quit > 0 ) 
    {
        SDL_Log( "TTF was initialized %d times\n", ttf_quit );
        for ( ttf_quit; ttf_quit != 0; ttf_quit-- ) {
            TTF_Quit();
        }
    }
    
    // Renderer
    if ( ctx.window != nullptr ) { 
        SDL_DestroyWindow( ctx.window );
        SDL_Log( "Destroy Window\n" );
    }
    if ( ctx.renderer != nullptr ) {
        SDL_DestroyRenderer( ctx.renderer );
        SDL_Log( "Destroy Renderer\n" );
    }
    SDL_Quit();
}
