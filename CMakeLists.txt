cmake_minimum_required( VERSION 3.28.0 )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR} )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR} )

add_link_options( "/INCREMENTAL:NO" )
add_compile_options( "/MP" )

project( snake )

# Toggle SDL_ttf options
option( SDLTTF_HARFBUZZ "Use harfbuzz to improve text shaping" OFF )
option( SDLTTF_PLUTOSVG "Use plutosvg for color emoji support" OFF )

add_subdirectory( "Snake" )
add_subdirectory( "libs/SDL" )
add_subdirectory( "libs/SDL_ttf" )