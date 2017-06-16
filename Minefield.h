#pragma once

#include <array>
#include <string>

class MineGrid
{
public:
    MineGrid(std::array<std::array<char, 5>, 5>);

    std::array<std::array<char, 5>, 5> Minesweep();

private:
    char SearchAround(const int x, const int y);

    int ReturnNumberOfAdjacentMines(const int x, const int y);

    const int m_xSize = 5, m_ySize = 5;

    std::array<std::array<char, 5>, 5> m_mineGrid;
};