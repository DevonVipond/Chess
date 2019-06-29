#include<string>
#include <stdio.h>
#include<vector>
#include <stack>
#include <unordered_map>

#include "coordinate.h"
#include "pieces/pawn.h"
#include "pieces/knight.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/king.h"
#include "pieces/queen.h"

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

/**
 * The Singleton ChessBoard is used to store the location of all chess pieces on the board
*/

class ChessBoard{
public:
    ~ChessBoard();

    /*
     * Returns pointer to Singleton
    */
    static ChessBoard* getInstance();

    // TODO : Destructor
    //~ChessBoard();

    Piece* getPiece(Coordinate location);
    Piece* getPiece(int x, int y);

    // TODO move out
    void setFirstSelectedPiece(Coordinate c){this->firstSelectedPiece = c;}
    Coordinate getFirstSelectedPiece(){return firstSelectedPiece;}

    bool movePiece(Player p, Coordinate src, Coordinate dest, bool simulatingMove=false);
    /*
     * Returns the player in checkmate, or returns UNKNOWN if no player
     * is in checkmate
    */
    Player checkmate();
    bool inDanger(Coordinate location, Player player=Player::UNKNOWN);
    /*
     * Reverts the previous move
    */
    void undoMove();
    /*
     * Reverts the previous move and returns true if a captured piece was restored
    */
    bool undoAndRestorePiece();

private:
    ChessBoard();
    ChessBoard(const ChessBoard& rhs) = delete;

    static ChessBoard* onlyInstance;
    std::vector<std::vector<Piece*>> board;

    struct previousMove
    {
        Coordinate src;
        Coordinate dest;
        Piece* capturedPiece=nullptr;

        previousMove(Coordinate src, Coordinate dest, Piece* capturedPiece=nullptr)
        {
            this->src = src;
            this->dest = dest;
            this->capturedPiece = capturedPiece;
        }
    };
    std::stack<previousMove> previousMoves;

    // TODO move into view/controller
    Coordinate firstSelectedPiece;
};
#endif // CHESSBOARD_H
