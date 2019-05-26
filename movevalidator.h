#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

#include "chessboard.h"
//
///*
// * Used to validate moves and handle moving/capturing pieces.
// * Is a friend of class ChessBoard.
//*/
//class MoveValidator
//{
//public:
//    /*
//     * Checks if a piece can be moved from src to dest
//     * If Dest contains a piece that can be captured, calls moveAndCapture to handle the move
//     * Otherwise moves the piece from src to dest
//    */
//    bool movePiece(Player p, Coordinate src, Coordinate dest);
//    friend class ChessBoard;
//private:
//    /*
//     * If a piece at src can capture a piece at dest this function will handle that
//     * move and return true.
//     * Otherwise return false.
//    */
//    bool moveAndCapture(Coordinate src, Coordinate dest);
//};

#endif // MOVEVALIDATOR_H
