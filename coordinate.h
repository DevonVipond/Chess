#ifndef COORDINATE_H
#define COORDINATE_H

#include "translations.h"

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
