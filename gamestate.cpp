#include "gamestate.h"

GameState::GameState()
{
    whichPlayersTurn = Player::WHITE;
}

GameState* GameState::onlyInstance;

GameState* GameState::getInstance()
{
    if (onlyInstance == nullptr)
    {
        onlyInstance = new GameState();
    }

    return onlyInstance;
}

void GameState::endTurn()
{
    whichPlayersTurn = whichPlayersTurn==Player::WHITE ? Player::BLACK:Player::WHITE;
}
