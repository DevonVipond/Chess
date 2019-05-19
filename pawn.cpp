#include "pawn.h"
#include "cmath"

Pawn::Pawn(Player p) : Piece()//, moveDiagonal(false), x(1), y(1)
{
    player = p;
    moveDiagonal = false;
    x = 1;
    y = 1;
    move = new HorizontalVertical();
}

bool Pawn::validMove(Coordinate src, Coordinate dest)
{
    return move->validMove(src, dest, 1, 1);
}

char Pawn::display() const
{
    return icon;
}

#include <iostream>
bool Pawn::validMove(Coordinate src, Coordinate dest)
{
    int deltaX = abs(src.getX()-dest.getX());
    int deltaY = abs(src.getY()-dest.getY());

    std::cout << "deltaX: " << deltaX << std::endl;
    std::cout << "deltaY: " << deltaY << std::endl;

    if((deltaX == x && deltaY == 0) || (deltaX == 0 && deltaY == y))
    {
        std::cout << "returning true in validMove\n";
        return true;
    }

    std::cout << "returning false in validMove\n";

    return false;
}
