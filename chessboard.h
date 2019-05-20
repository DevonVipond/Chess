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

// Singleton
class ChessBoard{
public:
    ~ChessBoard();

    char displayPiece(Coordinate location) const;

    // Singleton
    static ChessBoard* getInstance();
    bool movePiece(Player p, Coordinate from, Coordinate to);
    bool capturePiece(Coordinate src, Coordinate dest);
    void displayBoard() const;
    std::vector<std::vector<char>> getBoardAsVector() const;
    const Piece* getPiece(int x, int y) const;

    Coordinate getFirstSelectedPiece(){return firstSelectedPiece;}
    void setFirstSelectedPiece(Coordinate c){this->firstSelectedPiece = c;}
private:
    ChessBoard();
    ChessBoard(const ChessBoard& rhs) = delete;

    // TODO: add removedPieces
    static ChessBoard* onlyInstance;
    std::vector<std::vector<Piece*>> board;
    std::vector<Piece*> capturedBlackPieces;
    std::vector<Piece*> capturedWhitePieces;
    Coordinate firstSelectedPiece;
};
#endif // CHESSBOARD_H
