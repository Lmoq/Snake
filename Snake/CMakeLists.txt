cmake_minimum_required( VERSION 3.28.0 )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR} )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR} )

add_link_options( "/INCREMENTAL:NO" )
add_compile_options( "/MP" )

# Invoke a list dir command to get all cpp source files
execute_process( 
	COMMAND powershell "Get-ChildItem -Path . -Recurse -Name | findstr cpp"
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/Snake/

	OUTPUT_VARIABLE FILES
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
# Convert output to list
separate_arguments( FILES_LIST NATIVE_COMMAND ${FILES} )

set( SOURCES ${FILES_LIST})
add_executable( ${PROJECT_NAME} ${SOURCES} )


target_include_directories( ${PROJECT_NAME} PRIVATE "include" )
target_link_libraries( ${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf )
