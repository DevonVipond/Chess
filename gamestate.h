#include "coordinate.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:
    static GameState* getInstance();
    Player currentPlayersTurn(){return whichPlayersTurn;}
    void endTurn();

    // TODO:
    //bool inCheckmate();
private:
    GameState();
    GameState(const GameState& rhs) = delete;

    static GameState* onlyInstance;

    Player whichPlayersTurn;
    //std::vector<Piece*> capturedBlackPieces;
    //std::vector<Piece*> capturedWhitePieces;
};

#endif // GAMESTATE_H
