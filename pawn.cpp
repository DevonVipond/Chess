#include "pawn.h"
#include "cmath"

Pawn::Pawn(Player p) : Piece()
{
    player = p;
    moveDiagonal = false;
    x = 1;
    y = 1;
    move = new HorizontalVertical();
    moveAndCapture = new Diagonal();
}

bool Pawn::validMove(Coordinate src, Coordinate dest)
{
    return move->validMove(src, dest, 1, 1);
}

/*
 * Pawn is the only piece that does not capture in the same
 * direction that it moves which is why validCapture is only being overwritten
 * for the Pawn piece
*/
bool Pawn::validCapture(Coordinate src, Coordinate dest)
{
    return moveAndCapture->validMove(src, dest, 1, 1);
}
