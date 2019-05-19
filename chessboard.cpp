#include <stdio.h>
#include <iostream>
#include <fstream>

#include "chessboard.h"

ChessBoard::ChessBoard()
{
    //std::vector<char> initBoard[8] = {'r', 'k', 'b', 'q', 'k', 'b', 'k', 'r'};
    auto createFrontline = [&](Player owner)
    {
        vector<Piece*> row;
        for(int i = 0; i < MAX_WIDTH; i++)
            row.push_back(new Pawn(owner));

        return row;
    };

    // TODO leaving as pawns for now
    auto createBackline = [&](Player owner)
    {
        vector<Piece*> row;
        for(int i = 0; i < MAX_WIDTH; i++)
            row.push_back(new Pawn(owner));

        return row;
    };

    // create player 1's pieces
    board.push_back(createBackline(Player::BLACK));
    board.push_back(createFrontline(Player::BLACK));

    vector<Piece*> emptyRow(8, nullptr);
    for(int i = 0; i < 4; i++)
        board.push_back(emptyRow);

    // create player 2's pieces
    board.push_back(createFrontline(Player::WHITE));
    board.push_back(createBackline(Player::WHITE));
}

//ChessBoard::~ChessBoard()
//{
//
//}

ChessBoard* ChessBoard::onlyInstance;

ChessBoard* ChessBoard::getInstance()
{
    if (onlyInstance == nullptr)
    {
        onlyInstance = new ChessBoard();
    }

    return onlyInstance;
}

char ChessBoard::displayPiece(Coordinate location) const
{
    if(!location.isValid())
        return '!';

    if(board[location.getX()][location.getY()] != nullptr)
        return board[location.getX()][location.getY()]->display();

    return '.';
}

// Assume the move is valid
bool ChessBoard::capturePiece(Coordinate src, Coordinate dest)
{
    // TODO: if king return
    // TODO: king cant move into danger
    if(!src.isValid() || !dest.isValid())
        return false;

    Piece* srcPiece = board[src.getX()][src.getY()];
    Piece* capturedPiece = board[dest.getX()][dest.getY()];

    if(srcPiece == nullptr || capturedPiece == nullptr)
        return false;

    // A player can't capture his own piece
    if(srcPiece->getPlayer() == capturedPiece->getPlayer())
        return false;

   if(capturedPiece->getPlayer() == Player::BLACK)
   {
       capturedBlackPieces.push_back(capturedPiece);
   }
   else if (capturedPiece->getPlayer() == Player::WHITE)
   {
       capturedWhitePieces.push_back(capturedPiece);
   }
   else
   {
       return false;
   }

   board[dest.getX()][dest.getY()] = board[src.getX()][src.getY()];
   board[src.getX()][src.getY()] = nullptr;

   return true;
}

#include <iostream>
// TODO: consider moving into the controller into a ValidChessMove Class
bool ChessBoard::movePiece(Player p, Coordinate src, Coordinate dest)
{
    // TODO: king cant move into danger
    if(!src.isValid() || !dest.isValid())
        return false;

    Piece* srcPiece = board[src.getX()][src.getY()];

    // TODO: Currently no support for eliminating pieces
    if(srcPiece ==  nullptr || (board[dest.getX()][dest.getY()] != nullptr &&
                                board[dest.getX()][dest.getY()]->getPlayer() == p))
    {
        // No piece exists here, return false
        std::cout << "piece is null \n";
        return false;
    }

    bool validMove = srcPiece->validMove(src, dest);

    if(validMove)
    {
        if(!capturePiece(src, dest))
        {
            board[dest.getX()][dest.getY()] = srcPiece;
            board[src.getX()][src.getY()] = nullptr;
        }
    }
    std::cout << "end of movePiece \n";

    return validMove;
}

// TODO should this class be able to interface with the console???
// consider making this return the board as a vector
void ChessBoard::displayBoard() const
{
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            std::cout << this->getInstance()->displayPiece(Coordinate(r, c));
        }
        std::cout << "\n";
    }
}
