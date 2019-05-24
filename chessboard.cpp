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

        row.push_back(new Rook(owner));
        row.push_back(new Knight(owner));
        row.push_back(new Bishop(owner));

        row.push_back(new Pawn(owner));
        row.push_back(new Pawn(owner));

        row.push_back(new Bishop(owner));
        row.push_back(new Knight(owner));
        row.push_back(new Rook(owner));

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

ChessBoard* ChessBoard::onlyInstance;

ChessBoard* ChessBoard::getInstance()
{
    if (onlyInstance == nullptr)
    {
        onlyInstance = new ChessBoard();
    }

    return onlyInstance;
}

//void ChessBoard::displayBoard() const
//{
//    for(int r = 0; r < 8; r++){
//        for(int c = 0; c < 8; c++){
//            std::cout << this->getInstance()->displayPiece(Coordinate(r, c));
//        }
//        std::cout << "\n";
//    }
//}

// Returns the chessboard as a vector of chars
//std::vector<std::vector<std::string>> ChessBoard::getBoardAsVector() const
//{
//    vector<std::vector<std::string>> ret;
//    vector<std::string> emptyRow;
//    for(int r = 0; r  < MAX_HEIGHT; r++)
//    {
//        ret.push_back(emptyRow);
//        for(int c = 0; c  < MAX_WIDTH; c++)
//        {
//            ret[r].push_back(getInstance()->displayPiece(Coordinate(r, c)));
//        }
//    }
//
//    for(int r = 0; r < 8; r++){
//        for(int c = 0; c < 8; c++){
//            std::cout << ret[r][c];
//        }
//        std::cout << "\n";
//    }
//
//    return ret;
//}

Piece* ChessBoard::getPiece(int x, int y)
{
    return board[x][y];
}

#include <iostream>
// TODO: consider moving into the controller into a ValidChessMove Class
bool ChessBoard::movePiece(Player p, Coordinate src, Coordinate dest)
{
    std::cout << "in movePiece\n";
    // TODO: king cant move into danger
    if(!src.isValid() || !dest.isValid())
        return false;

    Piece* srcPiece = board[src.getX()][src.getY()];

    /*
     * If no piece exits at src or
     * if a piece exists at dest belongs to the same player, return false.
     */
    if(srcPiece ==  nullptr || (board[dest.getX()][dest.getY()] != nullptr &&
                                board[dest.getX()][dest.getY()]->getPlayer() == p))
    {
        // No piece exits at src, return false
        std::cout << "piece is null \n";
        return false;
    }

    bool validMove = srcPiece->validMove(src, dest);

    if(validMove)
    {
        Piece* destPiece = board[dest.getX()][dest.getY()];
        Player srcPlayer = srcPiece->getPlayer();

        // Check if its possible for srcPiece to capture destPiece
        if(destPiece && srcPlayer != destPiece->getPlayer())
        {
            std::cout << "destPiece: " << destPiece << endl;
            Player destPlayer = destPiece->getPlayer();
            // Capture destPiece
            switch(destPlayer)
            {
                //case Player::BLACK:
                //    capturedBlackPieces.push_back(destPiece);
                //    break;

                //case Player::WHITE:
                //    capturedWhitePieces.push_back(destPiece);
                //    break;
                //default:
                //    std::cout << "unable to determine player \n";
                //    return false;

                delete destPiece;
            }
        }

        // Move Piece from src -> dest
        std::cout << "moving piece \n";
        board[dest.getX()][dest.getY()] = srcPiece;
        board[src.getX()][src.getY()] = nullptr;

    }

    std::cout << "end of movePiece \n";
    return validMove;
}
