#ifndef COORDINATE_H
#define COORDINATE_H

// TODO put in Dimensions namespace
static const int MAX_WIDTH = 8;
static const int MAX_HEIGHT = 8;
static const int MIN_WIDTH = 0;
static const int MIN_HEIGHT = 0;

static const int EMPTY_COORDINATE = -1;

enum Player
{
    BLACK,
    WHITE,
    UNKNOWN
};

class Coordinate{
public:
    Coordinate(int x=EMPTY_COORDINATE, int y=EMPTY_COORDINATE);

    bool setCoordinate(int x, int y);
    bool isValid();
    void clear();

    int getX() const;
    int getY() const;
    Coordinate& operator=(const Coordinate &lhs);
private:
    bool valid = false;
    int x, y;
};

bool operator==(const Coordinate &rhs, const Coordinate &lhs);
#endif // COORDINATE_H
