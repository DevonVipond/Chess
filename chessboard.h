#include<string>
#include <stdio.h>
#include<vector>
#include <unordered_map>

#include "coordinate.h"
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"

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

    bool movePiece(Player p, Coordinate src, Coordinate dest);
    /*
     * Returns the player in checkmate, or returns UNKNOWN if no player
     * is in checkmate
    */
    Player checkmate();
    bool inDanger(Coordinate location, Player player=Player::UNKNOWN);

private:
    ChessBoard();
    ChessBoard(const ChessBoard& rhs) = delete;

    static ChessBoard* onlyInstance;
    std::vector<std::vector<Piece*>> board;

    // TODO move into view/controller
    Coordinate firstSelectedPiece;
};
#endif // CHESSBOARD_H
