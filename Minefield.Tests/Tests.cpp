#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Minefield.cpp"
#include <array>

namespace MinefieldTests
{
    const int xSize = 5, ySize = 5;
    using u_grid = std::array<std::array<char, 5>, 5>;

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
            u_grid expectedGrid = BlankGridGenerator();
            
            MineGrid NoMines(expectedGrid);
            u_grid actualGrid = NoMines.Minesweep();

            AssertEntireGrid(expectedGrid, actualGrid);
		}

        TEST_METHOD(Grid_squares_with_mines_should_not_have_a_number)
        {
            u_grid expectedGrid = BlankGridGenerator();
            expectedGrid[0][1] = '*';

            MineGrid MinePersistence(expectedGrid);
            u_grid actualGrid = MinePersistence.Minesweep();

            Assert::AreEqual(expectedGrid[0][1], actualGrid[0][1]);

            /* -------------------- SECOND CASE -------------------- */
            u_grid expectedGrid2 = BlankGridGenerator();
            expectedGrid2[3][4] = '*';

            MineGrid MinePersistenceAlternate(expectedGrid2);
            u_grid actualGrid2 = MinePersistenceAlternate.Minesweep();

            Assert::AreEqual(expectedGrid2[3][4], actualGrid2[3][4]);
        }

        TEST_METHOD(Mines_above_are_counted)
        {
            u_grid expectedGrid = BlankGridGenerator();
            expectedGrid[1][1] = '*';
            expectedGrid[1][0] = '1';

            MineGrid MinesAbove(expectedGrid);
            u_grid actualGrid = MinesAbove.Minesweep();
            Assert::AreEqual(expectedGrid[1][0], actualGrid[1][0]);

            /* -------------------- SECOND CASE -------------------- */
            u_grid expectedGrid2 = BlankGridGenerator();
            expectedGrid2[2][2] = '*';
            expectedGrid2[2][1] = '1';

            MineGrid MinesAbove2(expectedGrid2);
            u_grid actualGrid2 = MinesAbove2.Minesweep();
            Assert::AreEqual(expectedGrid2[2][1], actualGrid2[2][1]);
        }

        TEST_METHOD(Mines_below_are_counted)
        {
            u_grid expectedGrid = BlankGridGenerator();
            expectedGrid[1][0] = '*';
            expectedGrid[1][1] = '1';

            MineGrid MinesAbove(expectedGrid);
            u_grid actualGrid = MinesAbove.Minesweep();
            Assert::AreEqual(expectedGrid[1][1], actualGrid[1][1]);

            /* -------------------- SECOND CASE -------------------- */
            u_grid expectedGrid2 = BlankGridGenerator();
            expectedGrid2[2][1] = '*';
            expectedGrid2[2][2] = '1';

            MineGrid MinesAbove2(expectedGrid2);
            u_grid actualGrid2 = MinesAbove2.Minesweep();
            Assert::AreEqual(expectedGrid2[2][2], actualGrid2[2][2]);
        }

        TEST_METHOD(Mines_to_the_left_are_counted)
        {
            u_grid expectedGrid = BlankGridGenerator();
            expectedGrid[1][0] = '*';
            expectedGrid[0][0] = '1';

            MineGrid MinesAbove(expectedGrid);
            u_grid actualGrid = MinesAbove.Minesweep();
            Assert::AreEqual(expectedGrid[0][0], actualGrid[0][0]);

            /* -------------------- SECOND CASE -------------------- */
            u_grid expectedGrid2 = BlankGridGenerator();
            expectedGrid2[2][1] = '*';
            expectedGrid2[1][1] = '1';

            MineGrid MinesAbove2(expectedGrid2);
            u_grid actualGrid2 = MinesAbove2.Minesweep();
            Assert::AreEqual(expectedGrid2[1][1], actualGrid2[1][1]);
        }
	};
}