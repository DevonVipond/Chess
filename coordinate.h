#ifndef COORDINATE_H
#define COORDINATE_H

// TODO put in Dimensions namespace
static const int MAX_WIDTH = 8;
static const int MAX_HEIGHT = 8;
static const int MIN_WIDTH = 0;
static const int MIN_HEIGHT = 0;

enum Player
{
    BLACK,
    WHITE,
    UNKNOWN
};

class Coordinate{
public:
    Coordinate(int x, int y){
        this->x = x;
        this->y = y;

        if(x >= MIN_WIDTH && x < MAX_WIDTH && y >= MIN_HEIGHT && y < MAX_HEIGHT) {
            this->valid = true;
        }
        else{
            this->valid = false;
        }
    }
    bool isValid() { return valid; }
    int getX() { return x; }
    int getY() { return y; }

private:
    bool validCoordinate(int x, int y){ }

    // members
    bool valid = false;
    int x=0, y=0;
};
#endif // COORDINATE_H
