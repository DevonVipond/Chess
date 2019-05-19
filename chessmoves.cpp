#include <math.h>
#include <iostream>

#include "chessmoves.h"

bool HorizontalVertical::validMove(Coordinate src, Coordinate dest, int maxX=0, int maxY=0)
{
    int deltaX = abs(src.getX()-dest.getX());
    int deltaY = abs(src.getY()-dest.getY());

    std::cout << "deltaX: " << deltaX << std::endl;
    std::cout << "deltaY: " << deltaY << std::endl;

    if((deltaX <= maxX && deltaY == 0) || (deltaX == 0 && deltaY <= maxY))
    {
        // TODO: check for obstructions
        std::cout << "returning true in validMove\n";
        return true;
    }

    return false;
}
