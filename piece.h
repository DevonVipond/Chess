#include "chessmoves.h"

#ifndef PIECEH_H
#define PIECEH_H

// TODO Consider removing player so piece does not need to know
// about other layers

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
    Piece() //: player(Player::UNKNOWN), moveDiagonal(false), x(0), y(0)
    {}
    virtual  ~Piece(){}

    Player getPlayer(){ return player; }
    virtual bool validMove(Coordinate src, Coordinate dest) = 0;
    virtual char display() const = 0;

protected:
    char icon;
    Player player;
    bool moveDiagonal;
    int x;
    int y;

    // Ensures that a chess move requested by the player is valid
    // Uses the strategy design pattern
    ChessMove* move;
};

#endif // PIECEH_H
