#include "bishop.h"

Bishop::Bishop(Player p) : Piece()
{
    player = p;
    moveDiagonal = false;
    x = 2;
    y = 1;
    move = new Diagonal();
}

bool Bishop::validMove(Coordinate src, Coordinate dest)
{
    return move->validMove(src, dest, 8, 8);
}
