#include "pieces/chessmoves.h"

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
    virtual  ~Piece(){ delete move; }

    virtual bool validMove(Coordinate src, Coordinate dest) = 0;
    virtual bool validCapture(Coordinate src, Coordinate dest){ return validMove(src, dest); }
    virtual std::string getName() = 0;

    Player getPlayer();
    bool canBeCaptured();

    /*
     * Returns the relative strength of the piece's position as an integer.
     *
     * Determined based on the piece's location
     * 	  - Positions near the center of the board and near enemy pieces are evaluated
     * 	    as being stronger because the piece can exert more dominance on the board
    */
    double positionStrength(Coordinate location);

protected:
    Player player=Player::UNKNOWN;
    bool moveDiagonal;
    bool beCaptured=true;

    int x;
    int y;

    /*
     * 2D array holding the strength of a position on the board
    */
    std::vector<std::vector<double>> strengthArray;

    /*
     * Ensures that a chess move requested by the player is valid
     * Assigned to a derived class using the strategy design pattern
    */
    ChessMove* move;
};

#endif // PIECEH_H
