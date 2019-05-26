#include "chessmoves.h"

#ifndef PIECEH_H
#define PIECEH_H

/*
 * Base class for all chess pieces
 *
 * Used to keep track of which player owns which piece and
 * to ensure moves requested by the player are valid.
 *
 * Implements the strategy design pattern to assign ChessMove* move base class pointer to a
 * derived class describing possible movement for the piece
 *
*/

class Piece {
public:
    Piece(){}
    virtual  ~Piece(){}

    virtual bool validMove(Coordinate src, Coordinate dest) = 0;
    Player getPlayer();
    virtual std::string getName() = 0;

    /*
     * inDanger, inCheck and canBeCaptured are used for special handling of the King
    */
    bool inDanger(Coordinate location);
    bool inCheck(Coordinate location);
    bool canBeCaptured();

protected:
    Player player=Player::UNKNOWN;
    bool moveDiagonal;
    bool beCaptured=true;
    int x;
    int y;

    // Ensures that a chess move requested by the player is valid
    // Uses the strategy design pattern
    ChessMove* move;
};

#endif // PIECEH_H
