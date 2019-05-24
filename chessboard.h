#include<string>
#include <stdio.h>
#include<vector>

#include "coordinate.h"
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

using namespace std;

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

    // TODO: remove, only used for debugging
    //void displayBoard() const;
    Piece* getPiece(int x, int y);

    // TODO move out
    void setFirstSelectedPiece(Coordinate c){this->firstSelectedPiece = c;}
    Coordinate getFirstSelectedPiece(){return firstSelectedPiece;}

    bool movePiece(Player p, Coordinate src, Coordinate dest);

private:
    ChessBoard();
    ChessBoard(const ChessBoard& rhs) = delete;

    static ChessBoard* onlyInstance;
    std::vector<std::vector<Piece*>> board;

    std::vector<Piece*> capturedBlackPieces;
    std::vector<Piece*> capturedWhitePieces;

    // TODO move into view/controller
    Coordinate firstSelectedPiece;
};
#endif // CHESSBOARD_H
