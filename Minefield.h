#pragma once

#include <array>

class MineGrid
{
public:
    MineGrid(std::array<std::array<char, 5>, 5>);

    std::array<std::array<char, 5>, 5> Minesweep();

private:
    const int m_xSize = 5, m_ySize = 5;

    std::array<std::array<char, 5>, 5> m_mineGrid;
};