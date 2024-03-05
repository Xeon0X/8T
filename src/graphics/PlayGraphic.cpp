#include "Graphic.h"
#include "../core/Game.h"
#include "../core/Card.h"

int main()
{
    // Graphic graphic;
    // graphic.play();

    Game game;
    game.setAllCard();

    Card card("name", "description", 1, "pathCardImage", "pathCardSound");

    card.applyCard(game.getAllCard());

    return 0;
}