#include "king.h"

King::King(Player p) : Piece()
{
    player = p;
    moveDiagonal = false;
    beCaptured = false;
    x = 1;
    y = 1;
    move = new AllDirections();
}

bool King::validMove(Coordinate src, Coordinate dest)
{
    return move->validMove(src, dest, 1, 1);
}

