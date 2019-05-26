#include "queen.h"
#include "king.h"
#include "chessboard.h"

Queen::Queen(Player p) : Piece()
{
    player = p;
    moveDiagonal = false;
    x = 1;
    y = 1;
    move = new AllDirections();
}

bool Queen::validMove(Coordinate src, Coordinate dest)
{
    return move->validMove(src, dest, 1, 1);
}
