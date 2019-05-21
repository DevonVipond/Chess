#include "coordinate.h"


Coordinate::Coordinate(int x, int y)
{
    setCoordinate(x, y);
}

bool Coordinate::isValid()
{
    if(x >= MIN_WIDTH && x < MAX_WIDTH && y >= MIN_HEIGHT && y < MAX_HEIGHT) {
        valid = true;
    }
    else{
        valid = false;
    }

    return valid;
}

void Coordinate::clear() {
    x = EMPTY_COORDINATE;
    y = EMPTY_COORDINATE;

    valid = false;
}

bool Coordinate::setCoordinate(int x, int y)
{
    this->x = x;
    this->y = y;

    return this->isValid();
}

int Coordinate::getX() const
{
    return x;
}

int Coordinate::getY() const
{
    return y;
}

Coordinate& Coordinate::operator=(const Coordinate &rhs)
{
    this->x = rhs.getX();
    this->y = rhs.getY();
}

bool operator==(const Coordinate &rhs, const Coordinate &lhs)
{
    return rhs.getX() == lhs.getX() && rhs.getY() == lhs.getY();
}
