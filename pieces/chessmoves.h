#ifndef CHESSMOVES_H
#define CHESSMOVES_H

#include "coordinate.h"

/*
 * Base class for a series of classes used to describe the possible movements
 * of various chess pieces
*/
class ChessMove
{
public:
    ChessMove(){}
    ~ChessMove(){}

    virtual bool validMove(Coordinate src, Coordinate dest, int maxX, int maxY) = 0;
};

/*
 * Used to describe the movement for pieces that can either move
 * horizontally or vertically such as Rooks, Pawns
*/
class HorizontalVertical : public ChessMove
{
public:
    HorizontalVertical(){}
    ~HorizontalVertical(){}

    bool validMove(Coordinate src, Coordinate dest, int maxX, int maxY) override;
};

/*
 * Movement for Knight
*/
class LShape : public ChessMove
{
public:
    LShape(){}
    ~LShape(){}

    bool validMove(Coordinate src, Coordinate dest, int maxX, int maxY) override;
};

/*
 * Movement for Bishop
*/
class Diagonal : public ChessMove
{
public:
    Diagonal(){}
    ~Diagonal(){}

    bool validMove(Coordinate src, Coordinate dest, int maxX, int maxY) override;
};

/*
 * Movement for King and Queen
*/
class AllDirections : public ChessMove
{
public:
    AllDirections();
    ~AllDirections(){}

    bool validMove(Coordinate src, Coordinate dest, int maxX, int maxY) override;

private:
    ChessMove* horizontalVertical;
    ChessMove* diagonal;
};

#endif // CHESSMOVES_H
