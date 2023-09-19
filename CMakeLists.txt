cmake_minimum_required( VERSION 3.7.0 )
project( toto LANGUAGES C )

file(GLOB SOURCES
    "toto.c"
)

find_package( SDL2 )

include_directories(${SDL2_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

