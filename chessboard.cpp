#include <stdio.h>
#include <iostream>
#include <fstream>

#include "chessboard.h"
#include "gamestate.h"
using namespace std;

ChessBoard::ChessBoard()
{
    auto createFrontline = [&](Player owner)
    {
        vector<Piece*> row;
        for(int i = 0; i < MAX_WIDTH; i++)
            row.push_back(new Pawn(owner));

        return row;
    };

    auto createBackline = [&](Player owner)
    {
        vector<Piece*> row;

        row.push_back(new Rook(owner));
        row.push_back(new Knight(owner));
        row.push_back(new Bishop(owner));

        row.push_back(new King(owner));
        row.push_back(new Queen(owner));

        row.push_back(new Bishop(owner));
        row.push_back(new Knight(owner));
        row.push_back(new Rook(owner));

        return row;
    };

    // create black pieces
    board.push_back(createBackline(Player::BLACK));
    board.push_back(createFrontline(Player::BLACK));

    vector<Piece*> emptyRow(8, nullptr);
    for(int i = 0; i < 4; i++)
        board.push_back(emptyRow);

    // create white pieces
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

Piece* ChessBoard::getPiece(int x, int y)
{
    return board[x][y];
}

#include <iostream>
// TODO: consider moving into the controller into a ValidChessMove Class
bool ChessBoard::movePiece(Player p, Coordinate src, Coordinate dest)
{
    // TODO: king cant move into danger
    if(!src.isValid() || !dest.isValid())
        return false;

    Piece* srcPiece = board[src.getX()][src.getY()];
    auto gameState = GameState::getInstance();

    /*
     * If no piece exits at src or
     * if its not the given players turn, return false.
     */
    if(srcPiece ==  nullptr || srcPiece->getPlayer() != gameState->currentPlayersTurn())
    {
        // No piece exits at src, return false
        std::cout << "piece is null \n";
        return false;
    }

    if(!srcPiece->canBeCaptured())
    {
        if(srcPiece->inDanger(dest))
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
            if(!destPiece->canBeCaptured())
                return false;

            std::cout << "destPiece: " << destPiece << endl;
            Player destPlayer = destPiece->getPlayer();

            // TODO: store captured pieces
            delete destPiece;
        }
        else if(destPiece && srcPlayer == destPiece->getPlayer())
            return false;

        // Move Piece from src -> dest
        std::cout << "moving piece \n";
        board[dest.getX()][dest.getY()] = srcPiece;
        board[src.getX()][src.getY()] = nullptr;

        gameState->endTurn();
    }

    std::cout << "end of movePiece \n";
    return validMove;
}
