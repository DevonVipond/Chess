#include "rook.h"

Rook::Rook(Player p) : Piece()
{
    player = p;
    moveDiagonal = false;
    x = 8;
    y = 8;
    move = new HorizontalVertical();
}

bool Rook::validMove(Coordinate src, Coordinate dest)
{
    return move->validMove(src, dest, 8, 8);
}
