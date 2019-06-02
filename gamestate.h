#include "coordinate.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:
    static GameState* getInstance();
    Player currentPlayersTurn(){return whichPlayersTurn;}
    void endTurn();
    void endGame(Player winner);
    Player getWinner();
    bool isGameOver();

private:
    GameState();
    GameState(const GameState& rhs) = delete;

    static GameState* onlyInstance;

    Player whichPlayersTurn;
    bool gameOver;
    Player winningPlayer=Player::UNKNOWN;
    //std::vector<Piece*> capturedBlackPieces;
    //std::vector<Piece*> capturedWhitePieces;
};

#endif // GAMESTATE_H
