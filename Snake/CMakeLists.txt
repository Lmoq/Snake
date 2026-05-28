cmake_minimum_required( VERSION 3.20.0 )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR} )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR} )

add_link_options( "/INCREMENTAL:NO" "/CGTHREADS:8" )
add_compile_options( "/MP" )


set( SOURCES
	"src/main.cpp"
	"src/app.cpp"
	"src/timer.cpp"
	
	# Gui
	"src/gui/texts/text.cpp"

	# Game states
	"src/states/game_states/game_state.cpp"
	"src/states/game_states/menu_state.cpp"
	"src/render/render.cpp"
)
add_executable( ${PROJECT_NAME} ${SOURCES} )

target_include_directories( ${PROJECT_NAME} PRIVATE "include" )
target_link_libraries( ${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf )
