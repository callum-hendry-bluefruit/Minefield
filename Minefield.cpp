#include "Minefield.h"

void main(){}

MineGrid::MineGrid(std::array<std::array<char, 5>, 5> input)
{
    m_mineGrid = input;
}

std::array<std::array<char, 5>, 5> MineGrid::Minesweep()
{
    std::array<std::array<char, 5>, 5> outputGrid;

    for (int y = 0; y < m_ySize; y++)
    {
        for (int x = 0; x < m_xSize; x++)
        {
            if (m_mineGrid[x][y] == '*')
            {
                outputGrid[x][y] = '*';
            }
            else
            {
                outputGrid[x][y] = SearchAround(x, y);
            }
        }
    }

    return outputGrid;
}

char MineGrid::SearchAround(const int x, const int y)
{
    int mineCount = ReturnNumberOfAdjacentMines(x, y);
    char numberOfMines = '0' + mineCount;
    return numberOfMines;
}

int MineGrid::ReturnNumberOfAdjacentMines(const int y, const int x)
{
    std::array<char, 8> m_currentSurroundings;

    for (int i = 0; i < 8; i++)
    {
        m_currentSurroundings[i] = '.';
    }

    if ((y + 1) <= (m_ySize - 1))
    { //Up
        m_currentSurroundings[0] = m_mineGrid[x][(y + 1)];
    }

    /*if ((y - 1) >= 0)
    { //Down
        m_currentSurroundings[1] = m_mineGrid[x][(y - 1)];
    }

    if ((x + 1) <= (m_xSize - 1))
    { //Left
       m_currentSurroundings[2] = m_mineGrid[(x + 1)][y]; 
    }

    if ((x - 1) >= 0)
    { //Right
        m_currentSurroundings[3] = m_mineGrid[(x - 1)][y];
    }

    if (((y - 1) >= 0) && ((x - 1) >= 0))
    { //Up-left
        m_currentSurroundings[4] = m_mineGrid[(x - 1)][(y - 1)];
    }

    if (((y + 1) <= (m_ySize - 1)) && ((x - 1) >= 0))
    { //Down-left
        m_currentSurroundings[5] = m_mineGrid[(x - 1)][(y + 1)];
    }

    if (((y - 1) >= 0) && ((x + 1) <= (m_xSize - 1)))
    { //Up-right
        m_currentSurroundings[6] = m_mineGrid[(x + 1)][(y - 1)];
    }

    if (((y + 1) <= (m_ySize - 1)) && ((x + 1) <= (m_xSize - 1)))
    { //Down-right
        m_currentSurroundings[7] = m_mineGrid[(x + 1)][(y + 1)];
    }*/

    int mineCount = 0;
    for (int i = 0; i < 8; i++)
    {
        if (m_currentSurroundings[i] == '*')
        {
            mineCount += 1;
        }
    }
    return mineCount;
}