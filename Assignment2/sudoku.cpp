#include <iostream>
using namespace std;

#define N 9 // Sudoku is a 9x9 grid

// Function to print the Sudoku
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

// Check if placing num at grid[row][col] is valid
bool isSafe(int grid[N][N], int row, int col, int num)
{
    // Check row
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Check column
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

// Solve Sudoku using Backtracking (CSP Approach)
bool solveSudoku(int grid[N][N])
{
    int row = -1, col = -1;
    bool isEmpty = true;

    // Find an empty cell (denoted by 0)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
            break;
    }

    // If no empty cell -> Sudoku solved
    if (isEmpty)
        return true;

    // Try numbers 1 to 9 (domain values)
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {                         // Check constraints
            grid[row][col] = num; // Assign value

            // Recursively solve next cell
            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0; // Undo and backtrack
        }
    }
    return false; // Trigger backtracking
}

// Main Function
int main()
{
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    cout << "Original Sudoku:\n";
    printGrid(grid);

    if (solveSudoku(grid))
    {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists!";
    }

    return 0;
}
