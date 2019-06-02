#include "piece.h"
#include "chessboard.h"
#include "coordinate.h"

bool Piece::canBeCaptured()
{
    return beCaptured;
}

Player Piece::getPlayer()
{
    return player;
}
