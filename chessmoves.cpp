#include <math.h>
#include <iostream>

#include "chessmoves.h"
#include "chessboard.h"

bool HorizontalVertical::validMove(Coordinate src, Coordinate dest, int maxX=1, int maxY=1)
{
    int deltaX = abs(src.getX()-dest.getX());
    int deltaY = abs(src.getY()-dest.getY());

    auto board = ChessBoard::getInstance();

    if (deltaX <= maxX && deltaY == 0)
    {
        // Ensure no pieces are obstructing the move
        int min = src.getX() < dest.getX() ? src.getX() : dest.getX();
        int max = src.getX() > dest.getX() ? src.getX() : dest.getX();

        for(int i = min+1; i < max; i++)
        {
            if(board->getPiece(i, src.getY()) != nullptr)
                return false;
        }

        return true;
    }
    else if (deltaX == 0 && deltaY <= maxY)
    {
        // Ensure no pieces are obstructing the move
        int min = src.getY() < dest.getY() ? src.getY() : dest.getY();
        int max = src.getY() > dest.getY() ? src.getY() : dest.getY();

        for(int i = min+1; i < max; i++)
        {
            if(board->getPiece(src.getX(), i) != nullptr)
                return false;
        }

        return true;
    }

    return false;
}

bool LShape::validMove(Coordinate src, Coordinate dest, int maxX=2, int maxY=1)
{
    int deltaX = abs(src.getX()-dest.getX());
    int deltaY = abs(src.getY()-dest.getY());

    if((deltaX == maxX && deltaY == maxY) || (deltaX == maxY && deltaY == maxX))
    {
        return true;
    }

    return false;
}

bool Diagonal::validMove(Coordinate src, Coordinate dest, int maxX=8, int maxY=8)
{
    int deltaX = abs(src.getX()-dest.getX());
    int deltaY = abs(src.getY()-dest.getY());

    auto board = ChessBoard::getInstance();

    if(deltaX == deltaY)
    {
        // Check if any pieces are obstructing the move
        Coordinate min = src.getY() < dest.getY() ? src : dest;
        Coordinate max = src.getY() > dest.getY() ? src : dest;

        int xSign = max.getX() < min.getX() ? -1 : 1;

        for(int i = 1; i < max.getY()-min.getY(); i++)
        {
            if(board->getPiece(min.getX() + xSign*i, min.getY() + i) != nullptr)
                return false;
        }

        return true;
    }

    return false;
}
