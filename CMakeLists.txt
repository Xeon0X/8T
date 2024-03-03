cmake_minimum_required (VERSION 3.11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v4.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

project(8T
  LANGUAGES CXX
  VERSION 1.0.0
)

set(SOURCE_FILES_GRAPHIC
    src/core/Game.cpp
    src/core/Player.cpp
    src/core/Card.cpp
    src/core/Case.cpp
    src/core/Deck.cpp
    src/core/Grid.cpp
    src/core/Piece.cpp
    src/graphics/PlayGraphic.cpp
    src/graphics/Graphic.cpp
    src/graphics/GridGraphic.cpp
)

set(SOURCE_FILES_CONSOLE
    src/core/Game.cpp
    src/core/Player.cpp
    src/core/Card.cpp
    src/core/Case.cpp
    src/core/Deck.cpp
    src/core/Grid.cpp
    src/core/Piece.cpp
    src/console/playConsole.cpp
    src/console/Console.cpp
)

set(CMAKE_BINARY_DIR ../bin)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(graphic ${SOURCE_FILES_GRAPHIC})
target_include_directories(graphic PUBLIC src/core src/graphics)
target_link_libraries(graphic PUBLIC SDL2main SDL2 SDL2_image SDL2_ttf)

add_executable(console ${SOURCE_FILES_CONSOLE})
target_include_directories(console PUBLIC src/core src/console)
target_include_directories(console PRIVATE src)

target_link_libraries(console
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)
