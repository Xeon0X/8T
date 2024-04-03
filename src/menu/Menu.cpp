#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>
#include "../graphics/Graphic.h"

void drawMenu(ImGuiIO &io, GameState &gamestate, Graphic &graphic, SDL_Renderer *renderer, SDL_Window *window)
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("Game Menu", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

    ImGui::SetWindowFontScale(1.7f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize("The Turbocharged, Topsy-Turvy, Transmutable Tic-Tac-Toe!").x) * 0.5f);
    ImGui::SetCursorPosY(100);

    ImGui::Text("The Turbocharged, Topsy-Turvy, Transmutable Tic-Tac-Toe!");
    ImGui::Separator();

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y - 50) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.8f, 0.8f, 0.8f, 1.0f));

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));

    if (ImGui::Button("Play", ImVec2(200, 50)))
    {
        gamestate = GameState::ChooseGameMode;
    }

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y + 100) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    if (ImGui::Button("Options", ImVec2(200, 50)))
    {
        gamestate = GameState::Options;
    }
    ImGui::PopStyleColor();

    ImGui::End();
}

void menu(SDL_Window *window, ImGuiIO &io, GameState &gamestate, SDL_Event &event, Graphic &graphic, SDL_Renderer *renderer)
{
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT)
        {
            gamestate = GameState::Quit;
        }
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
    drawMenu(io, gamestate, graphic, renderer, window);
    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(window);
}

void drawChooseGameModeMenu(ImGuiIO &io, GameState &gamestate, Graphic &graphic, SDL_Window *window, SDL_Renderer *renderer)
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("Game Mode Menu", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

    ImGui::SetWindowFontScale(1.7f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize("Game Mode Menu").x) * 0.5f);
    ImGui::SetCursorPosY(100);

    ImGui::Text("Game Mode Menu");
    ImGui::Separator();

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y - 50) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.8f, 0.8f, 0.8f, 1.0f));

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));

    if (ImGui::Button("Local", ImVec2(200, 50)))
    {
        gamestate = GameState::GameCreation;
    }

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y + 100) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    if (ImGui::Button("Multiplayer", ImVec2(200, 50)))
    {
        gamestate = GameState::Game;
    }
    ImGui::SetCursorPosY(ImGui::GetWindowSize().y - 100);
    ImGui::SetCursorPosX(50);

    if (ImGui::Button("Back", ImVec2(200, 50)))
    {
        gamestate = GameState::Menu;
    }
    ImGui::PopStyleColor(); // Restore default text color

    ImGui::End();
}

void chooseGameModeMenu(SDL_Window *window, ImGuiIO &io, GameState &gamestate, SDL_Event &event, Graphic &graphic, SDL_Renderer *renderer)
{
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT)
        {
            gamestate = GameState::Quit;
        }
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
    drawChooseGameModeMenu(io, gamestate, graphic, window, renderer);
    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(window);
}

void drawPauseMenu(ImGuiIO &io, GameState &gamestate, Graphic &graphic)
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("Pause Menu", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

    ImGui::SetWindowFontScale(1.7f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize("Pause Menu").x) * 0.5f);
    ImGui::SetCursorPosY(100);

    ImGui::Text("Pause Menu");
    ImGui::Separator();

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y - 50) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.8f, 0.8f, 0.8f, 1.0f));

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));

    if (ImGui::Button("Resume", ImVec2(200, 50)))
    {
        gamestate = GameState::Game;
    }

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y + 100) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    if (ImGui::Button("Options", ImVec2(200, 50)))
    {
        gamestate = GameState::Options;
    }
    ImGui::SetCursorPosY((ImGui::GetWindowSize().y + 250) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    if (ImGui::Button("Exit", ImVec2(200, 50)))
    {
        gamestate = GameState::Menu;
    }
    ImGui::PopStyleColor();

    ImGui::End();
}

void pauseMenu(SDL_Window *window, ImGuiIO &io, GameState &gamestate, SDL_Event &event, Graphic &graphic)
{
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT)
        {
            gamestate = GameState::Quit;
        }
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
    drawPauseMenu(io, gamestate, graphic);
    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(window);
}

void drawGameCreation(ImGuiIO &io, GameState &gamestate, Graphic &graphic, SDL_Window *window, SDL_Renderer *renderer)
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("Game Creation", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

    ImGui::SetWindowFontScale(1.7f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize("Game Creation").x) * 0.5f);
    ImGui::SetCursorPosY(100);

    ImGui::Text("Game Creation");
    ImGui::Separator();

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y - 50) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.8f, 0.8f, 0.8f, 1.0f));

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));

    static int player1Shape = 0;
    static int player1Color = 0;
    static int player2Shape = 0;
    static int player2Color = 0;

    const char *shapes[] = {"Croix", "Rond", "Triangle", "Carrée"};
    const char *colors[] = {"Rouge", "Bleu", "Vert", "Jaune"};

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    float windowWidth = ImGui::GetWindowSize().x;
    float textWidth, comboWidth;

    ImVec2 oldCursorPos = ImGui::GetCursorPos();

    ImGui::SetCursorPos(ImVec2(-9999, -9999));
    ImGui::Combo("##invisible", &player1Shape, shapes, IM_ARRAYSIZE(shapes));
    comboWidth = ImGui::GetItemRectSize().x;
    textWidth = ImGui::CalcTextSize("Joueur 1").x;

    ImGui::SetCursorPos(oldCursorPos);
    ImGui::SetCursorPosX((windowWidth - textWidth) / 2);
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 100);

    ImGui::Text("Joueur 1");
    textWidth = ImGui::CalcTextSize("Joueur 1").x;
    ImGui::SetCursorPosX((windowWidth - comboWidth) / 2);
    ImGui::Combo("Forme1", &player1Shape, shapes, IM_ARRAYSIZE(shapes));
    ImGui::SetCursorPosX((windowWidth - comboWidth) / 2);
    ImGui::Combo("Couleur1", &player1Color, colors, IM_ARRAYSIZE(colors));

    ImGui::SetCursorPosX((windowWidth - textWidth) / 2);

    ImGui::Text("Joueur 2");
    textWidth = ImGui::CalcTextSize("Joueur 2").x;
    ImGui::SetCursorPosX((windowWidth - comboWidth) / 2);
    ImGui::Combo("Forme2", &player2Shape, shapes, IM_ARRAYSIZE(shapes));
    ImGui::SetCursorPosX((windowWidth - comboWidth) / 2);
    ImGui::Combo("Couleur2", &player2Color, colors, IM_ARRAYSIZE(colors));

    ImGui::PopStyleColor();
    ImGui::SetCursorPosY(ImGui::GetWindowSize().y - 100);
    ImGui::SetCursorPosX(ImGui::GetWindowSize().x - 250);

    if (ImGui::Button("Start", ImVec2(200, 50)))
    {
        if (player1Shape != player2Shape || player1Color != player2Color)
        {
            gamestate = GameState::Game;

            char shape1;
            char shape2;
            if (shapes[player1Shape] == "Croix")
            {
                shape1 = 'X';
            }
            else if (shapes[player1Shape] == "Rond")
            {
                shape1 = 'O';
            }
            else if (shapes[player1Shape] == "Triangle")
            {
                shape1 = 'T';
            }
            else
            {
                shape1 = 'C';
            }

            if (shapes[player2Shape] == "Croix")
            {
                shape2 = 'X';
            }
            else if (shapes[player2Shape] == "Rond")
            {

                shape2 = 'O';
            }
            else if (shapes[player2Shape] == "Triangle")
            {
                shape2 = 'T';
            }
            else
            {
                shape2 = 'C';
            }
            if (shape1 != shape2 && colors[player1Color] != colors[player2Color])
            {
                Player player1 = Player(std::string(1, shape1), std::string(colors[player1Color]));
                Player player2 = Player(std::string(1, shape2), std::string(colors[player2Color]));
                graphic = *(new Graphic(window, renderer, player1, player2));
            }
        }
    }

    ImGui::SetCursorPosY(ImGui::GetWindowSize().y - 100);
    ImGui::SetCursorPosX(50);

    if (ImGui::Button("Back", ImVec2(200, 50)))
    {
        gamestate = GameState::ChooseGameMode;
    }
    ImGui::PopStyleColor();

    ImGui::End();
}
void gameCreation(SDL_Window *window, ImGuiIO &io, GameState &gamestate, SDL_Event &event, Graphic &graphic, SDL_Renderer *renderer)
{
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT)
        {
            gamestate = GameState::Quit;
        }
    }

    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
    drawGameCreation(io, gamestate, graphic, window, renderer);
    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(window);
}

int start()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        return 1;
    }

    if (TTF_Init() != 0)
    {
        std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
        exit(1);
    }
    int screenWidth, screenHeight;
    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
    {
        std::cout << "SDL_GetDesktopDisplayMode Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    screenWidth = dm.w;
    screenHeight = dm.h;

    srand(time(NULL));

    SDL_Window *window = SDL_CreateWindow("8T", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    if (renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 330");

    GameState gamestate = GameState::Menu;
    Graphic graphic(window, renderer);

    SDL_Event event;

    while (gamestate != GameState::Quit && SDL_GetWindowFlags(window) & SDL_WINDOW_SHOWN)
    {

        switch (gamestate)
        {
        case GameState::Menu:
            menu(window, io, gamestate, event, graphic, renderer);
            break;
        case GameState::Game:
            graphic.play(gamestate);

            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext();
            ImGui::CreateContext();
            ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
            ImGui_ImplOpenGL3_Init("#version 330");

            break;
        case GameState::Pause:
            pauseMenu(window, io, gamestate, event, graphic);
            break;
        case GameState::ChooseGameMode:
            chooseGameModeMenu(window, io, gamestate, event, graphic, renderer);
            break;
        case GameState::Options:
            break;
        case GameState::GameCreation:
            gameCreation(window, io, gamestate, event, graphic, renderer);
            break;
        default:
            break;
        }
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

int main()
{
    return start();
}
