cmake_minimum_required (VERSION 3.11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

project(8T
  LANGUAGES CXX
  VERSION 1.0.0
)

set(CMAKE_BINARY_DIR ../bin)
make_directory(${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)

# --- Fetch FTXUI --------------------------------------------------------------

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v4.0.0
  GIT_PROGRESS    TRUE
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# --- Fetch SDL2 ---------------------------------------------------------------

if (WIN32)
  FetchContent_Declare(
    SDL2
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL
    GIT_PROGRESS    TRUE
  )

  FetchContent_Declare(
    SDL2_IMAGE
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL_image
    GIT_PROGRESS    TRUE
  )

  FetchContent_Declare(
    SDL2_TTF
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL_ttf
    GIT_PROGRESS    TRUE
  )

  FetchContent_MakeAvailable(SDL2 SDL2_IMAGE SDL2_TTF)

endif (WIN32)

set(SDL_LIBRARIES ${SDL_LIBRARIES} SDL2main SDL2 SDL2_image SDL2_ttf)

# --- GRAPHIC ------------------------------------------------------------------

set(SOURCE_FILES_GRAPHIC
    src/core/Game.cpp
    src/core/Player.cpp
    src/core/Card.cpp
    src/core/Case.cpp
    src/core/Deck.cpp
    src/core/Grid.cpp
    src/core/Piece.cpp
    src/core/rules/Rules.cpp
    src/graphics/PlayGraphic.cpp
    src/graphics/Graphic.cpp
    src/graphics/GridGraphic.cpp
)

add_executable(graphic ${SOURCE_FILES_GRAPHIC})
target_include_directories(graphic PUBLIC src/core src/graphics)
target_link_libraries(graphic PUBLIC ${SDL_LIBRARIES})

# --- CONSOLE ------------------------------------------------------------------

set(SOURCE_FILES_CONSOLE
    src/core/Game.cpp
    src/core/Player.cpp
    src/core/Card.cpp
    src/core/Case.cpp
    src/core/Deck.cpp
    src/core/Grid.cpp
    src/core/Piece.cpp
    src/core/rules/Rules.cpp
    src/core/rules/RulesCommun.cpp
    src/core/rules/RulesRare.cpp
    src/core/rules/RulesEpic.cpp
    src/core/rules/RulesLegendaire.cpp
    src/console/playConsole.cpp
    src/console/Console.cpp
)

add_executable(console ${SOURCE_FILES_CONSOLE})
target_include_directories(console PUBLIC src/core src/core/rules src/console)
target_include_directories(console PRIVATE src)
target_link_libraries(console
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)
