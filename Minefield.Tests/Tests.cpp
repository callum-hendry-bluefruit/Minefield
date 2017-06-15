#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Minefield.cpp"
#include <array>

namespace MinefieldTests
{
    const int xSize = 5, ySize = 5;

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(With_no_mines_the_grid_should_be_all_zeros)
		{
            MineGrid NoMines;

            std::array<std::array<char, 5>, 5> expectedGrid;
            for (int i = 0; i < ySize; i++)
            {
                for (int j = 0; j < xSize; j++)
                {
                    expectedGrid[j][i] = '0';
                }
            }

            std::array<std::array<char, 5>, 5> actualGrid = NoMines.Minesweep();

            for (int i = 0; i < ySize; i++)
            {
                for (int j = 0; j < xSize; j++)
                {
                    Assert::AreEqual(expectedGrid[j][i], actualGrid[j][i]);
                }
            }
		}



        TEST_METHOD(Grid_squares_with_mines_should_not_have_a_number)
        {
            MineGrid MinePersistence;

            std::array<std::array<char, 5>, 5> expectedGrid;
            for (int i = 0; i < ySize; i++)
            {
                for (int j = 0; j < xSize; j++)
                {
                    expectedGrid[j][i] = '0';
                }
            }
            expectedGrid[0][1] = '*';

            std::array<std::array<char, 5>, 5> actualGrid = MinePersistence.Minesweep();

            for (int i = 0; i < ySize; i++)
            {
                for (int j = 0; j < xSize; j++)
                {
                    Assert::AreEqual(expectedGrid[j][i], actualGrid[j][i]);
                }
            }
        }

	};
}