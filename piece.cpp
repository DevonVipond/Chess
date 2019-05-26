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

/*
 * Returns true if an enemy piece is within capturing range of the parameter location.
 * Otherwise returns false.
*/
#include <iostream>
bool Piece::inDanger(Coordinate location)
{

    auto board = ChessBoard::getInstance();

    std::cout << "in inDanger\n";
    // Loop through all pieces on the board.
    for(int r = 0; r < MAX_WIDTH; r++)
    {
        for(int c = 0; c < MAX_HEIGHT; c++)
        {
            Piece *piece = board->getPiece(r, c);

            // Check if a piece exits at (r,c) and if its an enemy piece.
            if(piece != nullptr && piece->getPlayer() != player)
            {
                std::cout << "in inDanger first if\n";
                // If an enemy piece can capture the piece at location, return false.
                Coordinate src(r,c);
                if(piece->validMove(src, location))
                {
                    std::cout << "in inDanger second if\n";
                    return true;
                }
            }
        }
    }

    return false;
}

bool Piece::inCheck(Coordinate location)
{
    std::vector<std::vector<int>> shift = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

    for(std::vector<int> adj : shift)
    {
        Coordinate adjacentSquare(location.getX() + adj[0], location.getY() + adj[1]);
        if(!this->inDanger(adjacentSquare))
            return false;
    }

    return true;
}
