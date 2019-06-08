#include "pieces/piece.h"

#ifndef KING_H
#define KING_H

class King : public Piece {
public:
    King() : Piece() {}
    King(Player p);
    ~King() override {}

    bool validMove(Coordinate src, Coordinate dest) override;
    bool inCheck(Coordinate location);
    std::string getName() override{return player == Player::WHITE ? "WHITE_KING" : "BLACK_KING";}
};

#endif // KING_H
