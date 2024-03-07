#include "Rules.h"
#include "Game.h"

inline void EnablePosePiece(int cellX, int cellY, int CurrentGrid, Game &game)
{
    Player currentPlayer = game.getCurrentPlayer();
    PlayerEffects playerEffects = currentPlayer.getPlayerEffects();
    playerEffects.posePiece = true;
    currentPlayer.setPlayerEffects(playerEffects);
    game.replacePlayer(currentPlayer);
    game.setCurrentPlayer(currentPlayer);
}