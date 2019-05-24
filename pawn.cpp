#include "pawn.h"
#include "cmath"

Pawn::Pawn(Player p) : Piece()
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
