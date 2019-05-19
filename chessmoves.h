#ifndef CHESSMOVES_H
#define CHESSMOVES_H

#include "coordinate.h"

class ChessMove
{
public:
    ChessMove(){}
    ~ChessMove(){}

    virtual bool validMove(Coordinate src, Coordinate dest, int maxX, int maxY) = 0;
};

class HorizontalVertical : public ChessMove
{
public:
    HorizontalVertical(){}
    ~HorizontalVertical(){}

    bool validMove(Coordinate src, Coordinate dest, int maxX, int maxY) override;
};

#endif // CHESSMOVES_H
