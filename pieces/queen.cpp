#include "pieces/queen.h"
#include "pieces/king.h"
#include "models/chessboard.h"

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
    return move->validMove(src, dest, 8, 8);
}
