#include "knight.h"

Knight::Knight(Player p) : Piece()
{
    player = p;
    moveDiagonal = false;
    x = 2;
    y = 1;
    move = new LShape();
}

bool Knight::validMove(Coordinate src, Coordinate dest)
{
    return move->validMove(src, dest, 2, 1);
}

