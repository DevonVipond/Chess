#include "pieces/piece.h"
#include "models/chessboard.h"
#include "coordinate.h"

bool Piece::canBeCaptured()
{
    return beCaptured;
}

Player Piece::getPlayer()
{
    return player;
}
