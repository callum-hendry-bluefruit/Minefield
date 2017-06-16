#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Minefield.cpp"
#include <array>

namespace MinefieldTests
{
    const int xSize = 5, ySize = 5;

    std::array<std::array<char, 5>, 5> BlankGridGenerator()
    {
        std::array<std::array<char, 5>, 5> expectedGrid;
        for (int i = 0; i < ySize; i++)
        {
            for (int j = 0; j < xSize; j++)
            {
                expectedGrid[j][i] = '0';
            }
        }

        return expectedGrid;
    }

    void AssertEntireGrid(std::array<std::array<char, 5>, 5> expected, std::array<std::array<char, 5>, 5> actual)
    {
        for (int y = 0; y < ySize; y++)
        {
            for (int x = 0; x < xSize; x++)
            {
                Assert::AreEqual(expected[x][y], actual[x][y]);
            }
        }
    }

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(With_no_mines_the_grid_should_be_all_zeros)
		{
            std::array<std::array<char, 5>, 5> expectedGrid = BlankGridGenerator();
            
            MineGrid NoMines(expectedGrid);
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
            std::array<std::array<char, 5>, 5> expectedGrid = BlankGridGenerator();
            expectedGrid[0][1] = '*';

            MineGrid MinePersistence(expectedGrid);
            std::array<std::array<char, 5>, 5> actualGrid = MinePersistence.Minesweep();

            for (int i = 0; i < ySize; i++)
            {
                for (int j = 0; j < xSize; j++)
                {
                    Assert::AreEqual(expectedGrid[j][i], actualGrid[j][i]);
                }
            }

            /* -------------------- SECOND CASE -------------------- */
            std::array<std::array<char, 5>, 5> expectedGrid2 = BlankGridGenerator();
            expectedGrid2[3][4] = '*';

            MineGrid MinePersistenceAlternate(expectedGrid2);
            std::array<std::array<char, 5>, 5> actualGrid2 = MinePersistenceAlternate.Minesweep();

            for (int y = 0; y < ySize; y++)
            {
                for (int x = 0; x < xSize; x++)
                {
                    Assert::AreEqual(expectedGrid2[x][y], actualGrid2[x][y]);
                }
            }
        }

        TEST_METHOD(Mines_from_above_are_counted)
        {

        }
	};
}