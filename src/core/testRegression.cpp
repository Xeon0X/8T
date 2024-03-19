#include "Game.h"
#include "Case.h"
#include <cassert>

void TestRegression()
{
    Game game;
    Grid grid = game.getGrid(0);
    assert(grid.getGridHeight() == 3);
    assert(grid.getGridWidth() == 3);
    assert(grid.getNbAlignToWin() == 3);
    grid.setNbAlignToWin(4);
    assert(grid.getNbAlignToWin() == 4);

    game.createAndSetPiece(0, 0, 0);
    game.switchPlayer();
    game.createAndSetPiece(1, 0, 0);

    assert(game.getGrid(0).getCase(0, 0)->getPieces()[0].getSymbol() == "X");
    assert(game.getGrid(0).getCase(1, 0)->getPieces()[0].getSymbol() == "O");
}

int main()
{
    TestRegression();
    return 0;
}
