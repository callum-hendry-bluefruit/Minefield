#include "Minefield.h"

void main()
{

}

std::array<std::array<char, 5>, 5> MineGrid::Minesweep()
{
    std::array<std::array<char, 5>, 5> outputGrid;

    for (int y = 0; y < m_ySize; y++)
    {
        for (int x = 0; x < m_xSize; x++)
        {
            outputGrid[x][y] = '0';
        }
    }
    outputGrid[0][1] = '*';

    return outputGrid;
}