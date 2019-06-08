#include "gamestate.h"

GameState::GameState()
{
    whichPlayersTurn = Player::WHITE;
    gameOver = false;
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

void GameState::endGame(Player winner)
{
    gameOver = true;
    winningPlayer = winner;
}

Player GameState::getWinner()
{
    return winningPlayer;
}

bool GameState::isGameOver()
{
    return gameOver;
}
