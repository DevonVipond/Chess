#include "rook.h"

Rook::Rook(Player p) : Piece()
{
    icon = 'R';
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

char Rook::display() const
{
    return icon;
}
