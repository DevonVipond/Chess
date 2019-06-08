#include "pieces/piece.h"

#ifndef PAWN_H
#define PAWN_H

// TODO: first move can move two spaces
class Pawn : public Piece {
public:
    Pawn() : Piece()
    {}
    Pawn(Player p);
    ~Pawn() override {}

    bool validMove(Coordinate src, Coordinate dest) override;
    bool validCapture(Coordinate src, Coordinate dest);
    std::string getName() override{return player == Player::WHITE ? "WHITE_PAWN" : "BLACK_PAWN";}

private:
    ChessMove* moveAndCapture;
};

#endif // PAWN_H


