#include "Menu.h"

void Menu::drawMenu()
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(this->io->DisplaySize);
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
        this->gamestate = GameState::ChooseGameMode;
    }

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y + 100) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    if (ImGui::Button("Options", ImVec2(200, 50)))
    {
        this->gamestate = GameState::Options;
    }
    ImGui::PopStyleColor();

    ImGui::End();
}

void Menu::menu()
{
    while (SDL_PollEvent(&this->event))
    {
        ImGui_ImplSDL2_ProcessEvent(&this->event);
        if (this->event.type == SDL_QUIT)
        {
            this->gamestate = GameState::Quit;
        }
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    drawMenu();
    ImGui::Render();
    glViewport(0, 0, (int)this->io->DisplaySize.x, (int)this->io->DisplaySize.y);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(this->window);
}

void Menu::drawChooseGameModeMenu()
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(this->io->DisplaySize);
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
        this->gamestate = GameState::GameCreation;
    }

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y + 100) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    if (ImGui::Button("Multiplayer", ImVec2(200, 50)))
    {
        this->gamestate = GameState::Game;
    }
    ImGui::SetCursorPosY(ImGui::GetWindowSize().y - 100);
    ImGui::SetCursorPosX(50);

    if (ImGui::Button("Back", ImVec2(200, 50)))
    {
        this->gamestate = GameState::Menu;
    }
    ImGui::PopStyleColor(); // Restore default text color

    ImGui::End();
}

void Menu::chooseGameModeMenu()
{
    while (SDL_PollEvent(&this->event))
    {
        ImGui_ImplSDL2_ProcessEvent(&this->event);
        if (this->event.type == SDL_QUIT)
        {
            this->gamestate = GameState::Quit;
        }
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    drawChooseGameModeMenu();
    ImGui::Render();
    glViewport(0, 0, (int)this->io->DisplaySize.x, (int)this->io->DisplaySize.y);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(this->window);
}

void Menu::drawPauseMenu()
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(this->io->DisplaySize);
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
        this->gamestate = GameState::Game;
    }

    ImGui::SetCursorPosY((ImGui::GetWindowSize().y + 100) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    if (ImGui::Button("Options", ImVec2(200, 50)))
    {
        this->gamestate = GameState::Options;
    }
    ImGui::SetCursorPosY((ImGui::GetWindowSize().y + 250) * 0.5f);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 200) * 0.5f);

    if (ImGui::Button("Exit", ImVec2(200, 50)))
    {
        this->gamestate = GameState::Menu;
    }
    ImGui::PopStyleColor();

    ImGui::End();
}

void Menu::pauseMenu()
{
    while (SDL_PollEvent(&this->event))
    {
        ImGui_ImplSDL2_ProcessEvent(&this->event);
        if (this->event.type == SDL_QUIT)
        {
            this->gamestate = GameState::Quit;
        }
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    drawPauseMenu();
    ImGui::Render();
    glViewport(0, 0, (int)this->io->DisplaySize.x, (int)this->io->DisplaySize.y);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(this->window);
}

void Menu::drawGameCreation(Graphic &graphic)
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(this->io->DisplaySize);
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
        if (player1Shape != player2Shape && player1Color != player2Color)
        {
            this->gamestate = GameState::Game;

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
                graphic = *(new Graphic(this->window, this->renderer, player1, player2));
            }
        }
    }

    ImGui::SetCursorPosY(ImGui::GetWindowSize().y - 100);
    ImGui::SetCursorPosX(50);

    if (ImGui::Button("Back", ImVec2(200, 50)))
    {
        this->gamestate = GameState::ChooseGameMode;
    }
    ImGui::PopStyleColor();

    ImGui::End();
}
void Menu::gameCreation(Graphic &graphic)
{
    while (SDL_PollEvent(&this->event))
    {
        ImGui_ImplSDL2_ProcessEvent(&this->event);
        if (this->event.type == SDL_QUIT)
        {
            this->gamestate = GameState::Quit;
        }
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    drawGameCreation(graphic);
    ImGui::Render();
    glViewport(0, 0, (int)this->io->DisplaySize.x, (int)this->io->DisplaySize.y);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(this->window);
}

int main()
{
    Menu menu;
    menu.start();
    return 0;
}

void Menu::start()
{
    Graphic graphic = Graphic(this->window, this->renderer);
    while (this->gamestate != GameState::Quit && SDL_GetWindowFlags(this->window) & SDL_WINDOW_SHOWN)
    {

        switch (this->gamestate)
        {
        case GameState::Menu:
            this->menu();
            break;
        case GameState::Game:
            graphic.play(this->gamestate);

            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext();
            ImGui::CreateContext();
            ImGui_ImplSDL2_InitForOpenGL(this->window, this->gl_context);
            ImGui_ImplOpenGL3_Init("#version 330");

            break;
        case GameState::Pause:
            this->pauseMenu();
            break;
        case GameState::ChooseGameMode:
            this->chooseGameModeMenu();
            break;
        case GameState::Options:
            break;
        case GameState::GameCreation:
            this->gameCreation(graphic);
            break;
        default:
            break;
        }
    }
}

Menu::Menu()
{
    std::cout << "Menu constructor" << std::endl;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
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

    this->window = SDL_CreateWindow("8T", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (this->window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (this->renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    this->gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    this->io = &ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark(); // TODO add light mode
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 330");
}

Menu::~Menu()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(this->gl_context);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
