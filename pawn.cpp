#include "pawn.h"
#include "cmath"

Pawn::Pawn(Player p) : Piece()
{
    icon = 'P';
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
