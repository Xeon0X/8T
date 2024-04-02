#include "Graphic.h"
#include "Case.h"
#include <iostream>

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

    deckPart.x = 200;
    deckPart.y = 850;
    deckPart.w = 1500;
    deckPart.h = 300;

    pioche.x = 10;
    pioche.y = 500;
    pioche.w = 100;
    pioche.h = 150;

    this->cardClicked = nullptr;
}

Graphic::~Graphic()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
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

void Graphic::drawPlayer(int x, int y, int radius, int thickness, Player player)
{
    std::tuple<int, int, int> colorPlayer = player.stringToRgb();
    SDL_SetRenderDrawColor(renderer, std::get<0>(colorPlayer), std::get<1>(colorPlayer), std::get<2>(colorPlayer), 255);
    if (player.getSymbol() == "X")
    {
        drawCross(x, y, radius, thickness, player);
    }
    else
    {
        drawCircle(x, y, radius, thickness, player);
    }
}

void Graphic::play()
{
    while (running)
    {
        eventHolder();
        clear();

        grid.showGrid(renderer, *this);

        this->grid.drawPartInterface(renderer, *this);
        this->grid.drawDeck(renderer, *this);
        this->grid.drawGamerules(renderer, *this);
        this->grid.drawPioche(renderer, *this);
        this->grid.drawArrowDirection(renderer, *this);
        present();
    }
}

void Graphic::handleQuitEvent()
{
    running = false;
}

bool CoIncid(int x, int y, int x1, int y1, int x2, int y2)
{
    return (x >= x1 && x < x2 && y >= y1 && y < y2);
}

bool Graphic::MouseClickInterface(int x, int y)
{
    return CoIncid(x, y, this->deckPart.x, this->deckPart.y, this->deckPart.x + this->deckPart.w, this->deckPart.y + this->deckPart.h);
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

    // Play a card
    if (grid.getGlobalRules()[grid.getActualGlobalRule()]->getName() == "PlayCard") {
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

                    break;
                }
                else
                {
                    std::cout << "Card clicked" << std::endl;
                    this->isCardClicked = true;
                    this->setCard(deck.getCards()[i]);
                    grid.nextGlobalRule();
                    game.setGrid(CurrentGrid, grid);
                    this->grid.setGame(game); // Update the grid with next global rule
                    break;
                }
            }
        }
    }

    // Switchplayer
    if (grid.getGlobalRules()[grid.getActualGlobalRule()]->getName() == "SwitchPlayer") {
        game.switchPlayer();
        grid.nextGlobalRule();
        game.setGrid(CurrentGrid, grid);
        this->grid.setGame(game);
    }

    // Checkwin
    if (grid.getGlobalRules()[grid.getActualGlobalRule()]->getName() == "AlignToWin") {
        handleCheckWin(cellX, cellY, game);
        grid.nextGlobalRule();
        game.setGrid(CurrentGrid, grid);
        this->grid.setGame(game); // Update the grid with next global rule
    }

    // Draw a card
    if (CoIncid(mouseX, mouseY, this->pioche.x, this->pioche.y, this->pioche.x + this->pioche.w, this->pioche.y + this->pioche.h))
    {
        if (grid.getGlobalRules()[grid.getActualGlobalRule()]->getName() == "DrawCard") {
            std::cout << grid.getGlobalRules()[grid.getActualGlobalRule()]->getName();
            grid.nextGlobalRule();
            game.setGrid(0, grid);
            this->grid.setGame(game); // Update the grid with next global rule

            player.drawCard();
            this->grid.getGame().replacePlayer(player);
            this->grid.getGame().setCurrentPlayer(player); // Update the grid with the new card added to the player
        }
    }

    // Place a piece
    if (CoIncid(cellX, cellY, 0, 0, CasesWidth, CasesHeight) && !this->isCardClicked && !MouseClickInterface(mouseX, mouseY))
    {
        if (grid.getGlobalRules()[grid.getActualGlobalRule()]->getName() == "PlacePiece") {
            if (grid.getCase(cellX, cellY)->getPieces().size() > 0)
            {
                if (grid.getCase(cellX, cellY)->getPieces()[0].getSymbol() == game.getCurrentPlayer().getSymbol())
                {
                    // TODO : working with multiple pieces on one case
                }
            } else { // Place a piece on a new piece
                grid.nextGlobalRule();
                game.setGrid(0, grid);

                game.createAndSetPiece(cellX, cellY, CurrentGrid);
                player.getPlayerEffects().posePiece = false;

                game.replacePlayer(player);
                game.setCurrentPlayer(player);

                this->grid.setGame(game);
            }
                // this->cardClicked->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "up");
                // game.createAndSetPiece(cellX, cellY, CurrentGrid);
                // player.getPlayerEffects().posePiece = false;

                // game.replacePlayer(player);
                // game.setCurrentPlayer(player);

                // // handlecheckwin

                // game = this->grid.getGame();
                // game.switchPlayer();
        }
    }

    // Apply everything
    if (grid.getGlobalRules()[grid.getActualGlobalRule()]->getName() == "Gravity") {
        grid.nextGlobalRule();
        game.setGrid(0, grid);
        this->grid.setGame(game); // Update the grid with next global rule
    }

    // TODO : problem when clicking a card, then drawing, without clicking on an arrow
    // TODO : fix applycard : this is not supposed to show up
    // TODO : can't select an other card
    // TODO : add a card to globalRules
    // TODO : how to have everything inside the card and not here?
    // TODO : how to handle non player action automatically and not on click?
    
    #include <typeinfo>
    std::cout << typeid(decltype(deck.getCards()[0])).name() << std::endl;
    // deck.getCards()[0]->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "down");
    grid.getGlobalRules()[0]->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "down");
    std::cout << "test";
    for (int i = 0; i < grid.getGlobalRules().size(); i++) {
        std::cout << i;
        grid.getGlobalRules()[i]->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "down");
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

    if (CoIncid(mouseX, mouseY, arrowUpX, arrowUpY, arrowUpX + arrowUpWidth, arrowUpY + arrowUpHeight))
    {
        this->cardClicked->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "up");
        this->deleteCard();
        this->isCardClicked = false;
    }
    else if (CoIncid(mouseX, mouseY, arrowDownX, arrowDownY, arrowDownX + arrowDownWidth, arrowDownY + arrowDownHeight))
    {
        this->cardClicked->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "down");
        this->deleteCard();
        this->isCardClicked = false;
    }
    else if (CoIncid(mouseX, mouseY, arrowLeftX, arrowLeftY, arrowLeftX + arrowLeftWidth, arrowLeftY + arrowLeftHeight))
    {

        this->cardClicked->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "left");
        this->deleteCard();
        this->isCardClicked = false;
    }
    else if (CoIncid(mouseX, mouseY, arrowRightX, arrowRightY, arrowRightX + arrowRightWidth, arrowRightY + arrowRightHeight))
    {

        this->cardClicked->applyCard(0, 0, player.getCurrentGrid(), player, this->grid.getGame(), "right");
        this->deleteCard();
        this->isCardClicked = false;
    }
}

void Graphic::handleKeyDownEvent(SDL_Event &event)
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
    }
}

void Graphic::handleCheckWin(int cellX, int cellY, Game game)
{
    Grid grid = game.getGrid(game.getCurrentPlayer().getCurrentGrid());
    if (grid.checkWin(game.getCurrentPlayer(), cellX, cellY))
    {
        std::cout << "Player " << game.getCurrentPlayer().getSymbol() << " wins" << std::endl;
    }
}

void Graphic::eventHolder()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            handleQuitEvent();
            break;
        case SDL_MOUSEBUTTONDOWN:
            handleMouseButtonDownEvent(event);
            break;
        case SDL_KEYDOWN:
            handleKeyDownEvent(event);
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