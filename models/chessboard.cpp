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

Piece* ChessBoard::getPiece(Coordinate location)
{
    if(!location.isValid())
        return nullptr;

    return board[location.getX()][location.getY()];
}

Piece* ChessBoard::getPiece(int x, int y)
{
    Coordinate location(x,y);
    if(!location.isValid())
        return nullptr;

    return board[location.getX()][location.getY()];
}

#include <iostream>
bool ChessBoard::movePiece(Player p, Coordinate src, Coordinate dest, bool simulatingMove)
{
    if(!src.isValid() || !dest.isValid())
        return false;

    Piece* srcPiece = board[src.getX()][src.getY()];
    auto gameState = GameState::getInstance();

    /*
     * If no piece exits at src or
     * if its not the given players turn, return false.
     */
    if(srcPiece ==  nullptr || (srcPiece->getPlayer() != gameState->currentPlayersTurn()
            && !simulatingMove))
    {
        // No piece exits at src, return false
        std::cout << "Error: piece is either null or not this player's turn\n";
        return false;
    }

    if(!srcPiece->canBeCaptured())
    {
        // The king can not move into danger
        if(inDanger(dest, srcPiece->getPlayer()))
            return false;
    }

    bool validMove = srcPiece->validMove(src, dest);
    bool validCapture = srcPiece->validCapture(src, dest);

    if(validMove || validCapture)
    {
        Piece* destPiece = board[dest.getX()][dest.getY()];
        Player srcPlayer = srcPiece->getPlayer();

        // Check if its possible for srcPiece to capture destPiece
        if(destPiece && srcPlayer != destPiece->getPlayer())
        {
            if(!destPiece->canBeCaptured() || !srcPiece->validCapture(src, dest))
                return false;

            std::cout << "destPiece: " << destPiece << endl;
            Player destPlayer = destPiece->getPlayer();
        }
        else if(destPiece && srcPlayer == destPiece->getPlayer())
            return false;

        previousMove prevMove(src, dest, destPiece);
        previousMoves.push(prevMove);

        // Move Piece from src -> dest
        board[dest.getX()][dest.getY()] = srcPiece;
        board[src.getX()][src.getY()] = nullptr;

        // TODO: uncomment
        gameState->endTurn();
    }

    if(!simulatingMove)
    {
        Player potentialCheck = checkmate();
        if(potentialCheck != Player::UNKNOWN)
        {
            // Announce the winner and end the game
            gameState->endGame(potentialCheck);
        }
    }

    return validMove || validCapture;
}

void ChessBoard::undoMove()
{
    if(previousMoves.empty())
        return;

    previousMove prev = previousMoves.top();
    previousMoves.pop();

    Piece* destPiece =  board[prev.src.getX()][prev.src.getY()];
    board[prev.src.getX()][prev.src.getY()] =  board[prev.dest.getX()][prev.dest.getY()];
    board[prev.dest.getX()][prev.dest.getY()] =  board[prev.src.getX()][prev.src.getY()];
}

bool ChessBoard::undoAndRestorePiece()
{
    undoMove();

    if(!previousMoves.empty() && previousMoves.top().capturedPiece != nullptr)
        return true;

    return false;
}

/*
 * Returns true if an enemy piece is within capturing range of the parameter location.
 * Otherwise returns false.
*/
// TODO: bug - if testing move for a piece, the piece can obstruct enemy pieces
bool ChessBoard::inDanger(Coordinate location, Player player)
{
    auto board = ChessBoard::getInstance();

    // Loop through all pieces on the board.
    for(int r = 0; r < MAX_WIDTH; r++)
    {
        for(int c = 0; c < MAX_HEIGHT; c++)
        {
            Coordinate src(r,c);
            Piece *piece = board->getPiece(src);

            // Check if a piece exits at (r,c) and if its an enemy piece.
            if(piece != nullptr && piece->getPlayer() != player)
            {
                // If an enemy piece can capture the piece at location, return false.
                if(piece->validMove(src, location)) // TODO: special handling for pawns
                {
                    std::cout << "returning true from inDanger \n";
                    return true;
                }
            }
        }
    }

    std::cout << "Returning false from inDanger\n";
    return false;
}

Player ChessBoard::checkmate()
{
    auto board = ChessBoard::getInstance();

    for(int r = 0; r < MAX_WIDTH; r++)
        for(int c = 0; c < MAX_HEIGHT; c++)
        {
            Coordinate src(r,c);
            Piece* piece = board->getPiece(src);

            if(piece == nullptr)
                continue;

            std::string name = piece->getName();

            Coordinate location(r,c);
            if((name == "WHITE_KING" || name == "BLACK_KING") && inDanger(location, piece->getPlayer()))
            {
                std::vector<std::vector<int>> shift = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

                bool inCheck = true;
                for(std::vector<int> adj : shift)
                {
                    Coordinate adjacentSquare(r + adj[0], c + adj[1]);
                    Piece *adjacentPiece = this->getPiece(adjacentSquare);
                    if(adjacentSquare.isValid() && !inDanger(adjacentSquare, piece->getPlayer()) && (adjacentPiece == nullptr || adjacentPiece->getPlayer() != piece->getPlayer())) // TODO: BUg: enemy king
                    {
                        std::cout << "\nSetting inCheck to false\n" << std::endl;
                        std::cout << (adjacentPiece == nullptr ? "\nadjacentPiece: null\n" : "\nadjacentPiece not null\n");
                        inCheck = false;
                    }
                }

                if(inCheck)
                {
                    std::cout << "in Check\n";
                    // TODO: Check if friendly piece can obstruct the check
                    return piece->getPlayer();
                }
                else
                {
                    std::cout << "not in check\n";
                }
            }
        }

    return Player::UNKNOWN;
}
