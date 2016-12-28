#include "board.h"

board::board()
{
    for (int x = 0; x < boardSize; x++)
    {
        for (int y = 0; y < boardSize; y++)
        {
            lives[x][y] = false;
        }
    }
}

bool board::isAlive(int locX, int locY)
{
    return lives[locX][locY];
}
void board::toggleLife(int locX, int locY)
{
    lives[locX][locY] = !(lives[locX][locY]);
}
int board::numOfNeighbors(int locX, int locY)
{
    int minX = (locX - 1);
    int maxX = (locX + 1);
    int minY = (locY - 1);
    int maxY = (locY + 1);
    int livingNeighbors = 0;

    if (minX < 0)
    {
        minX = locX;
    }
    if(maxX >= boardSize)
    {
        maxX = locX;
    }
    if (minY < 0)
    {
        minY = locY;
    }
    if (maxY >= boardSize)
    {
        maxY = locY;
    }



    for (int x = minX; x <= maxX; x++)
    {
        for (int y = minY; y <= maxY; y++)
        {
            if (x == locX && y == locY)
            {
                continue;
            }
            else
            {
                if (isAlive(x, y))
                {
                    livingNeighbors++;
                }
            }
        }
    }

    return livingNeighbors;

}
void board::update()
{
    bool newBoard[boardSize][boardSize];
    int neighborNum = 0;

    for (int x = 0; x < boardSize; x++)
    {
        for (int y = 0; y < boardSize; y++)
        {
            newBoard[x][y] = lives[x][y];
        }
    }

    for (int x = 0; x < boardSize; x++)
    {
        for (int y = 0; y < boardSize; y++)
        {
            neighborNum = numOfNeighbors(x, y);
            if (isAlive(x, y))
            {
                if(neighborNum < 2)
                {
                    newBoard[x][y] = !lives[x][y];
                }
                else if(neighborNum > 3)
                {
                    newBoard[x][y] = !lives[x][y];
                }
            }
            else
            {
                if(neighborNum == 3)
                {
                    newBoard[x][y] = !lives[x][y];
                }
            }
        }
    }

    for (int x = 0; x < boardSize; x++)
    {
        for (int y = 0; y < boardSize; y++)
        {
            lives[x][y] = newBoard[x][y];
        }
    }

    return;
}

int board::getSize()
{
    return boardSize;
}
