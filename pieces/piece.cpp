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

double Piece::positionStrength(Coordinate location)
{
    if(!location.isValid() || strengthArray.empty())
        return -1.0;

    if(this->getPlayer() == Player::WHITE)
    {
        return strengthArray[location.getX()][location.getY()];
    }
    else if(this->getPlayer() == Player::BLACK)
    {
        return strengthArray[location.getX()][MAX_HEIGHT - location.getY() - 1];
    }
    else
    {
        return -1.0;
    }
}
