#include "Graphic.h"
#include "Case.h"
#include <iostream>
#include <SDL2/SDL_image.h>
Graphic::Graphic()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
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

    window = SDL_CreateWindow("8T", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0);

    if (window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    color = {0, 0, 0, 255};
    this->font = TTF_OpenFont("../font/dogica.ttf", 10);
    if (font == nullptr)
    {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        exit(1);
    }

    fontColor = {0, 0, 0, 255};
    fontSize = 10;
    fontStyle = TTF_STYLE_NORMAL;
    this->grid = GridGraphic();
    this->grid.setInitialGridSize(3, 3);
    this->grid.initCardTexture(renderer);

    deckPart.x = 200;
    deckPart.y = 850;
    deckPart.w = 1500;
    deckPart.h = 300;

    pioche.x = 10;
    pioche.y = 500;
    pioche.w = 150;
    pioche.h = 200;

    globalRuleButton.x = 100;
    globalRuleButton.y = 300;
    globalRuleButton.w = 200;
    globalRuleButton.h = 50;

    this->cardClicked = nullptr;
}

Graphic::Graphic(SDL_Window *window, SDL_Renderer *renderer, Player player1, Player player2)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    this->window = window;
    this->renderer = renderer;
    color = {0, 0, 0, 255};
    this->font = TTF_OpenFont("../font/dogica.ttf", 10);
    if (font == nullptr)
    {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        exit(1);
    }

    fontColor = {0, 0, 0, 255};
    fontSize = 10;
    fontStyle = TTF_STYLE_NORMAL;
    this->grid = GridGraphic(renderer, player1, player2);
    this->grid.initCardTexture(renderer);

    this->grid.setInitialGridSize(3, 3);

    deckPart.x = 200;
    deckPart.y = 850;
    deckPart.w = 1500;
    deckPart.h = 300;

    pioche.x = 10;
    pioche.y = 500;
    pioche.w = 150;
    pioche.h = 200;

    globalRuleButton.x = 100;
    globalRuleButton.y = 300;
    globalRuleButton.w = 200;
    globalRuleButton.h = 50;

    this->cardClicked = nullptr;
}

Graphic::Graphic(SDL_Window *window, SDL_Renderer *renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    this->window = window;
    this->renderer = renderer;
    color = {0, 0, 0, 255};
    this->font = TTF_OpenFont("../font/dogica.ttf", 10);
    if (font == nullptr)
    {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        exit(1);
    }

    fontColor = {0, 0, 0, 255};
    fontSize = 10;
    fontStyle = TTF_STYLE_NORMAL;
    this->grid = GridGraphic();
    this->grid.setInitialGridSize(3, 3);
    this->grid.initCardTexture(renderer);

    deckPart.x = 200;
    deckPart.y = 850;
    deckPart.w = 1500;
    deckPart.h = 300;

    pioche.x = 10;
    pioche.y = 500;
    pioche.w = 150;
    pioche.h = 200;

    globalRuleButton.x = 100;
    globalRuleButton.y = 300;
    globalRuleButton.w = 200;
    globalRuleButton.h = 50;

    this->cardClicked = nullptr;
}
Graphic::~Graphic()
{
}

void Graphic::drawRect(int x, int y, int w, int h)
{
    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void Graphic::drawLine(int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Graphic::drawCircle(int x, int y, int r, int thickness, Player player)
{
    std::tuple<int, int, int> colorPlayer = player.stringToRgb();
    SDL_SetRenderDrawColor(renderer, std::get<0>(colorPlayer), std::get<1>(colorPlayer), std::get<2>(colorPlayer), 255);

    for (int w = 0; w < thickness; ++w)
    {
        for (int i = 0; i < 360; ++i)
        {
            double angle = i * M_PI / 180.0;
            int px = x + (int)((r + w * 0.5) * cos(angle));
            int py = y + (int)((r + w * 0.5) * sin(angle));

            SDL_RenderDrawPoint(renderer, px, py);
        }
    }
}

void Graphic::drawCross(int x, int y, int r, int thickness, Player player)
{
    std::tuple<int, int, int> colorPlayer = player.stringToRgb();
    SDL_SetRenderDrawColor(renderer, std::get<0>(colorPlayer), std::get<1>(colorPlayer), std::get<2>(colorPlayer), 255);
    for (int z = 0; z < thickness; z++)
    {
        SDL_RenderDrawLine(renderer, x - r, y - r + z, x + r, y + r + z);
        SDL_RenderDrawLine(renderer, x - r, y + r + z, x + r, y - r + z);
    }
}

void Graphic::drawPoint(int x, int y)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Graphic::drawText(const char *text, int x, int y)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, fontColor);
    if (!surface)
    {
        std::cout << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
    {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    }
    SDL_Rect rect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Graphic::clear()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void Graphic::present()
{
    SDL_RenderPresent(renderer);
}

void Graphic::setColor(int r, int g, int b, int a)
{
    color = {(unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a};
}

void Graphic::setDrawColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(renderer, (unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a);
}

void Graphic::setFont(const char *font, int size)
{
    this->font = TTF_OpenFont(font, size);
}

void Graphic::setFontSize(int size)
{
    fontSize = size;
    TTF_CloseFont(font);
    font = TTF_OpenFont("res/arial.ttf", size);
}

void Graphic::setFontColor(int r, int g, int b, int a)
{
    fontColor = {(unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a};
}

void Graphic::setFontStyle(int style)
{
    fontStyle = style;
    TTF_SetFontStyle(font, style);
}

void Graphic::drawTriangle(int x, int y, int h, int thickness, Player player)
{
    std::tuple<int, int, int> colorPlayer = player.stringToRgb();
    SDL_SetRenderDrawColor(renderer, std::get<0>(colorPlayer), std::get<1>(colorPlayer), std::get<2>(colorPlayer), 255);

    int x1 = x - h / 2;
    int y1 = y + h / 2;
    int x2 = x + h / 2;
    int y2 = y + h / 2;
    int x3 = x;
    int y3 = y - h / 2;

    // Dessin des côtés du triangle
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2); // Bas
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3); // Droite
    SDL_RenderDrawLine(renderer, x3, y3, x1, y1); // Gauche
}

void Graphic::drawSquare(int x, int y, int sideLength, int thickness, Player player)
{
    std::tuple<int, int, int> colorPlayer = player.stringToRgb();
    SDL_SetRenderDrawColor(renderer, std::get<0>(colorPlayer), std::get<1>(colorPlayer), std::get<2>(colorPlayer), 255);

    int halfSideLength = sideLength / 2;
    int startX = x - halfSideLength;
    int startY = y - halfSideLength;

    for (int i = 0; i < sideLength; ++i)
    {
        for (int j = 0; j < sideLength; ++j)
        {
            if (i == 0 || i == sideLength - 1 || j == 0 || j == sideLength - 1)
            {
                SDL_RenderDrawPoint(renderer, startX + j, startY + i);
            }
        }
    }
}

void Graphic::drawPlayer(int x, int y, int radius, int thickness, Player player)
{
    std::tuple<int, int, int> colorPlayer = player.stringToRgb();
    SDL_SetRenderDrawColor(renderer, std::get<0>(colorPlayer), std::get<1>(colorPlayer), std::get<2>(colorPlayer), 255);
    if (player.getSymbol() == "X")
    {
        drawCross(x, y, radius, thickness, player);
    }
    else if (player.getSymbol() == "O")
    {
        drawCircle(x, y, radius, thickness, player);
    }
    else if (player.getSymbol() == "T")
    {
        drawTriangle(x, y, radius, thickness, player);
    }
    else if (player.getSymbol() == "C")
    {
        drawSquare(x, y, 50, thickness, player);
    }
}

void Graphic::play(GameState &gamestate)
{
    while (GameState::Game == gamestate)
    {

        time += 1;
        eventHolder(gamestate);
        clear();

        grid.showGrid(renderer, *this);

        this->grid.drawPartInterface(renderer, *this);
        this->grid.drawDeck(renderer, *this);
        this->grid.drawGlobalRuleButton(renderer, *this);
        this->grid.drawGlobalrules(renderer, *this);
        this->grid.drawPioche(renderer, *this);
        this->grid.drawArrowDirection(renderer, *this);

        present();
        gameloop();
    }
}

void Graphic::handleQuitEvent(GameState &gamestate)
{
    gamestate = GameState::Quit;
}

bool CoIncid(int x, int y, int x1, int y1, int x2, int y2)
{
    return (x >= x1 && x < x2 && y >= y1 && y < y2);
}

bool Graphic::MouseClickInterface(int x, int y)
{
    return CoIncid(x, y, this->deckPart.x, this->deckPart.y, this->deckPart.x + this->deckPart.w, this->deckPart.y + this->deckPart.h);
}

void Graphic::gameloop()
{
    if (time > 250)
    { // Wait to see the operation
        time = 0;
        int CurrentGrid = this->grid.getGame().getCurrentPlayer().getCurrentGrid();
        Player player = this->grid.getGame().getCurrentPlayer();
        Deck deck = player.getDeck(player.getCurrentGrid());
        Game game = this->grid.getGame();
        Grid grid = game.getGrid(CurrentGrid);

        grid.getGlobalRules()[grid.getCurrentGlobalRule()]->applyCard(0, 0, CurrentGrid, player, game, "default");
        this->grid.setGame(game);
    }
}

void Graphic::handleMouseButtonDownEvent(SDL_Event &event)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    int screenWidth, screenHeight;
    SDL_GetRendererOutputSize(renderer, &screenWidth, &screenHeight);

    int CurrentGrid = this->grid.getGame().getCurrentPlayer().getCurrentGrid();
    int CasesWidth = this->grid.getGame().getGrid(CurrentGrid).getGridWidth();
    int CasesHeight = this->grid.getGame().getGrid(CurrentGrid).getGridHeight();

    int gridX = ((screenWidth - CasesWidth * this->grid.getCaseWidth()) / 2) + this->grid.getGridX();
    int gridY = ((screenHeight - CasesHeight * this->grid.getCaseHeight()) / 2) + this->grid.getGridY();

    mouseX -= gridX;
    mouseY -= gridY;
    int cellX = -1;
    int cellY = -1;

    if (mouseX > 0 && mouseY > 0)
    {
        cellX = std::floor(mouseX / 100);
        cellY = std::floor(mouseY / 100);
    }

    Player player = this->grid.getGame().getCurrentPlayer();
    Deck deck = player.getDeck(player.getCurrentGrid());
    SDL_GetMouseState(&mouseX, &mouseY);

    Game game = this->grid.getGame();
    Grid grid = game.getGrid(CurrentGrid);

    handleArrowClick(mouseX, mouseY, screenWidth, screenHeight);
    handleGlobalRuleButtonClick(mouseX, mouseY, screenWidth, screenHeight);

    // Play a card
    if (grid.getRules().canPlayCard)
    {
        for (unsigned int i = 0; i < deck.getCards().size(); i++)
        {
            int cardX = (i + 1) * 110 + 500;
            int cardY = 775;
            int cardWidth = 100;
            int cardHeight = 150;

            if (CoIncid(mouseX, mouseY, cardX, cardY, cardX + cardWidth, cardY + cardHeight))
            {
                if (this->cardClicked == deck.getCards()[i])
                {
                    this->cardClicked = nullptr;
                    this->isCardClicked = false;
                    game.setGrid(CurrentGrid, grid);
                    break;
                }
                else
                {
                    std::cout << "Card clicked\n"
                              << std::endl;
                    this->isCardClicked = true;
                    this->setCard(deck.getCards()[i]);
                    this->grid.setGame(game); // Update the grid with next global rule
                    break;
                }
            }
        }
    }

    // // Checkwin
    // if (grid.getGlobalRules()[grid.getCurrentGlobalRule()]->getName() == "AlignToWin") {
    //     handleCheckWin(cellX, cellY, game);
    //     grid.nextGlobalRule();
    //     game.setGrid(CurrentGrid, grid);
    //     this->grid.setGame(game); // Update the grid with next global rule
    // }

    // Draw a card
    if (grid.getRules().canDrawCard)
    {
        if (CoIncid(mouseX, mouseY, this->pioche.x, this->pioche.y, this->pioche.x + this->pioche.w, this->pioche.y + this->pioche.h))
        {
            if (grid.getGlobalRules()[grid.getCurrentGlobalRule()]->getName() == "DrawCard")
            {
                std::cout << grid.getGlobalRules()[grid.getCurrentGlobalRule()]->getName();
                std::cout << "Draw a card\n"
                          << std::endl;
                grid.nextGlobalRule();
                GridRules rules = grid.getRules();

                rules.canDrawCard = false;
                grid.setRules(rules);
                game.setGrid(0, grid);
                this->grid.setGame(game); // Update the grid with next global rule

                player.drawCard();
                this->grid.getGame().replacePlayer(player);
                this->grid.getGame().setCurrentPlayer(player); // Update the grid with the new card added to the player
            }
        }
    }

    // Place a piece
    if (grid.getRules().canPlacePiece)
    {
        if (CoIncid(cellX, cellY, 0, 0, CasesWidth, CasesHeight) && !this->isCardClicked && !MouseClickInterface(mouseX, mouseY))
        {
            if (grid.getGlobalRules()[grid.getCurrentGlobalRule()]->getName() == "PlacePiece")
            {
                if (grid.getCase(cellX, cellY)->getPieces().size() > 0)
                {
                    if (grid.getCase(cellX, cellY)->getPieces()[0].getSymbol() == game.getCurrentPlayer().getSymbol())
                    {
                        // TODO : working with multiple pieces on one case
                    }
                }
                else
                { // Place a piece on a new piece
                    GridRules rules = grid.getRules();
                    rules.canPlacePiece = false;
                    grid.setRules(rules);
                    grid.nextGlobalRule();

                    game.setGrid(CurrentGrid, grid);
                    game.createAndSetPiece(cellX, cellY, CurrentGrid);

                    // TODO : manage player effect
                    // player.getPlayerEffects().posePiece = false;
                    // game.replacePlayer(player);
                    // game.setCurrentPlayer(player);

                    this->grid.setGame(game);
                }
            }
        }
    }
}

void Graphic::handleArrowClick(int mouseX, int mouseY, int screenWidth, int screenHeight)
{
    std::vector<std::vector<Case *>> grid = this->grid.getGame().getGrid(0).getCases();
    int GridWidth = grid[0].size() * 100;
    int GridHeight = grid.size() * 100;
    int startX = (screenWidth - GridWidth) / 2;
    int startY = (screenHeight - GridHeight) / 2;

    int endX = startX + GridWidth;
    int endY = startY + GridHeight;

    int arrowUpX = startX + GridWidth / 2 - 5 + this->grid.getGridX();
    int arrowUpY = startY - 50 + this->grid.getGridY();
    int arrowUpWidth = 10;
    int arrowUpHeight = 50;

    int arrowDownX = startX + GridWidth / 2 - 5 + this->grid.getGridX();
    int arrowDownY = endY + this->grid.getGridY();
    int arrowDownWidth = 10;
    int arrowDownHeight = 50;

    int arrowLeftX = startX - 50 + this->grid.getGridX();
    int arrowLeftY = startY + GridHeight / 2 - 5 + this->grid.getGridY();
    int arrowLeftWidth = 50;
    int arrowLeftHeight = 10;

    int arrowRightX = endX + this->grid.getGridX();
    int arrowRightY = startY + GridHeight / 2 - 5 + this->grid.getGridY();
    int arrowRightWidth = 50;
    int arrowRightHeight = 10;

    Player player = this->grid.getGame().getCurrentPlayer();

    int CurrentGrid = this->grid.getGame().getCurrentPlayer().getCurrentGrid();

    if (CoIncid(mouseX, mouseY, arrowUpX, arrowUpY, arrowUpX + arrowUpWidth, arrowUpY + arrowUpHeight))
    {
        this->cardClicked->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "up");
        this->deleteCard();
        this->isCardClicked = false;

        Grid gridForRules = this->grid.getGame().getGrid(CurrentGrid); // To rename
        gridForRules.nextGlobalRule();
        GridRules rules = gridForRules.getRules();
        rules.canPlayCard = false;
        gridForRules.setRules(rules);
        this->grid.getGame().setGrid(CurrentGrid, gridForRules);
    }
    else if (CoIncid(mouseX, mouseY, arrowDownX, arrowDownY, arrowDownX + arrowDownWidth, arrowDownY + arrowDownHeight))
    {
        this->cardClicked->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "down");
        this->deleteCard();
        this->isCardClicked = false;

        Grid gridForRules = this->grid.getGame().getGrid(CurrentGrid); // To rename
        gridForRules.nextGlobalRule();
        GridRules rules = gridForRules.getRules();
        rules.canPlayCard = false;
        gridForRules.setRules(rules);
        this->grid.getGame().setGrid(CurrentGrid, gridForRules);
    }
    else if (CoIncid(mouseX, mouseY, arrowLeftX, arrowLeftY, arrowLeftX + arrowLeftWidth, arrowLeftY + arrowLeftHeight))
    {

        this->cardClicked->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "left");
        this->deleteCard();
        this->isCardClicked = false;

        Grid gridForRules = this->grid.getGame().getGrid(CurrentGrid); // To rename
        gridForRules.nextGlobalRule();
        GridRules rules = gridForRules.getRules();
        rules.canPlayCard = false;
        gridForRules.setRules(rules);
        this->grid.getGame().setGrid(CurrentGrid, gridForRules);
    }
    else if (CoIncid(mouseX, mouseY, arrowRightX, arrowRightY, arrowRightX + arrowRightWidth, arrowRightY + arrowRightHeight))
    {

        this->cardClicked->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "right");
        this->deleteCard();
        this->isCardClicked = false;

        Grid gridForRules = this->grid.getGame().getGrid(CurrentGrid); // To rename
        gridForRules.nextGlobalRule();
        GridRules rules = gridForRules.getRules();
        rules.canPlayCard = false;
        gridForRules.setRules(rules);
        this->grid.getGame().setGrid(CurrentGrid, gridForRules);
    }
}

void Graphic::handleGlobalRuleButtonClick(int mouseX, int mouseY, int screenWidth, int screenHeight)
{
    Player player = this->grid.getGame().getCurrentPlayer();
    int CurrentGrid = this->grid.getGame().getCurrentPlayer().getCurrentGrid();
    Grid grid = this->grid.getGame().getGrid(CurrentGrid);

    if (CoIncid(mouseX, mouseY, globalRuleButton.x, globalRuleButton.y, globalRuleButton.x + globalRuleButton.w, globalRuleButton.y + globalRuleButton.h))
    {
        grid.addGlobalRule(this->cardClicked);
        this->deleteCard();
        this->isCardClicked = false;

        grid.nextGlobalRule();
        GridRules rules = grid.getRules();
        rules.canPlayCard = false;
        grid.setRules(rules);
        this->grid.getGame().setGrid(CurrentGrid, grid);
    }
}

void Graphic::handleKeyDownEvent(SDL_Event &event, GameState &gamestate)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
        this->grid.moveGrid(0, 10);
        break;
    case SDLK_DOWN:
        this->grid.moveGrid(0, -10);
        break;
    case SDLK_LEFT:
        this->grid.moveGrid(10, 0);
        break;
    case SDLK_RIGHT:
        this->grid.moveGrid(-10, 0);
        break;
    case SDLK_ESCAPE:
        gamestate = GameState::Pause;
        break;
    }
}

void Graphic::handleCheckWin(int cellX, int cellY, Game game)
{
    Grid grid = game.getGrid(game.getCurrentPlayer().getCurrentGrid());
    if (grid.checkWin(game.getCurrentPlayer(), cellX, cellY))
    {
        Player player = game.getCurrentPlayer();
        player.setScore(player.getScore() + 1);
        game.setCurrentPlayer(player);
        game.replacePlayer(player);
    }
    this->grid.setGame(game);
}

void Graphic::eventHolder(GameState &gamestate)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            this->handleQuitEvent(gamestate);
            break;
        case SDL_MOUSEBUTTONDOWN:
            this->handleMouseButtonDownEvent(event);
            break;
        case SDL_KEYDOWN:
            handleKeyDownEvent(event, gamestate);
            break;
        }
    }
}

bool Graphic::isCardEmpty()
{
    return this->cardClicked == nullptr;
}

void Graphic::deleteCard()
{
    Player player = this->grid.getGame().getCurrentPlayer();
    Deck deck = player.getDeck(player.getCurrentGrid());
    deck.removeCard(this->cardClicked);
    player.setDeck(player.getCurrentGrid(), deck);
    this->grid.getGame().replacePlayer(player);
    this->grid.getGame().setCurrentPlayer(player);
    this->cardClicked = nullptr;
}
void Graphic::setCard(Card *card)
{
    this->cardClicked = card;
}

Card *Graphic::getCard()
{
    return this->cardClicked;
}
