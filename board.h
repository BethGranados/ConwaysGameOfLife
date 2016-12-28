#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

//#define boardSize 50

class board
{
private:
    static const int boardSize = 50;
    bool lives[boardSize][boardSize];

public:
    board();
    bool isAlive(int locX, int locY);
    void toggleLife(int locX, int locY);
    int numOfNeighbors(int locX, int locY);
    void update();
    int getSize();
};


#endif // BOARD_H_INCLUDED
