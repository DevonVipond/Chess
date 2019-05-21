#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include <QString>

static const char NO_PIECE_ICON = '!';

static const QString IMAGE_DIRECTORY_PATH = ":/images/images/";

// Black Chess Piece Images:
static const QString BLACK_PAWN =  IMAGE_DIRECTORY_PATH + "pawn.png";
static const QString BLACK_KNIGHT =IMAGE_DIRECTORY_PATH + "horse.png";
static const QString BLACK_ROOK =  IMAGE_DIRECTORY_PATH + "rook.png";
static const QString BLACK_KING =  IMAGE_DIRECTORY_PATH + "king.png";
static const QString BLACK_QUEEN = IMAGE_DIRECTORY_PATH + "queen.png";

// White Chess Piece Images:
static const QString WHITE_PAWN =  IMAGE_DIRECTORY_PATH + "pawn_white.png";
static const QString WHITE_KNIGHT =IMAGE_DIRECTORY_PATH + "horse_white.png";
static const QString WHITE_ROOK =  IMAGE_DIRECTORY_PATH + "rook_white.png";
static const QString WHITE_KING =  IMAGE_DIRECTORY_PATH + "king_white.png";
static const QString WHITE_QUEEN = IMAGE_DIRECTORY_PATH + "queen_white.png";

// Board Dimensions
static const int MAX_WIDTH = 8;
static const int MAX_HEIGHT = 8;
static const int MIN_WIDTH = 0;
static const int MIN_HEIGHT = 0;

// Empty Coordinate value
static const int EMPTY_COORDINATE = -1;

enum Player
{
    BLACK,
    WHITE,
    UNKNOWN
};

char getPlayerAsChar(Player player)
{
    switch(player)
    {
        case Player::BLACK:
            return 'B';
        case Player::WHITE:
            return 'W';
        default:
            return 'U';
    };
}

#endif // TRANSLATIONS_H