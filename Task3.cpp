
#include <iostream>
using namespace std;

// Function to display Sudoku
void displayGrid(int grid[9][9])
{
    cout << "\n========== SUDOKU GRID ==========\n";

    for (int row = 0; row < 9; row++)
    {
        if (row % 3 == 0 && row != 0)
        {
            cout << "---------------------\n";
        }

        for (int col = 0; col < 9; col++)
        {
            if (col % 3 == 0 && col != 0)
            {
                cout << "| ";
            }

            cout << grid[row][col] << " ";
        }

        cout << endl;
    }
}

// Function to check whether a number is safe
bool isSafe(int grid[9][9], int row, int col, int num)
{
    // Check row
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Function to validate the original puzzle
bool isValidGrid(int grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            int num = grid[row][col];

            if (num != 0)
            {
                grid[row][col] = 0;

                if (!isSafe(grid, row, col, num))
                {
                    grid[row][col] = num;
                    return false;
                }

                grid[row][col] = num;
            }
        }
    }

    return true;
}

// Backtracking function to solve Sudoku
bool solveSudoku(int grid[9][9])
{
    int row = -1;
    int col = -1;
    bool emptyFound = false;

    // Find an empty cell
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                emptyFound = true;
                break;
            }
        }

        if (emptyFound)
        {
            break;
        }
    }

    // No empty cell means puzzle is solved
    if (!emptyFound)
    {
        return true;
    }

    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            // Place the number
            grid[row][col] = num;

            // Recursively solve remaining cells
            if (solveSudoku(grid))
            {
                return true;
            }

            // Backtrack: remove the number
            grid[row][col] = 0;
        }
    }

    // No number worked
    return false;
}

// Main function
int main()
{
    int grid[9][9];

    cout << "========== SUDOKU SOLVER ==========\n";

    cout << "Enter Sudoku grid (0 for empty cells):\n";

    // Input Sudoku grid
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] < 0 || grid[i][j] > 9)
            {
                cout << "Invalid input! Enter numbers from 0 to 9.\n";
                return 0;
            }
        }
    }

    cout << "\nOriginal Sudoku:";
    displayGrid(grid);

    // Validate original puzzle
    if (!isValidGrid(grid))
    {
        cout << "\nInvalid Sudoku puzzle! Duplicate numbers found.\n";
        return 0;
    }

    // Solve Sudoku
    if (solveSudoku(grid))
    {
        cout << "\nSudoku solved successfully!";
        displayGrid(grid);
    }
    else
    {
        cout << "\nNo solution exists for this Sudoku puzzle.\n";
    }

    return 0;
}
