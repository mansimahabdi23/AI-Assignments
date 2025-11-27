#include <iostream>
#include <vector>
using namespace std;

#define N 8 // Size of the chessboard (8x8)

// Function to print the board configuration
void printBoard(const vector<vector<int>> &board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << "\n";
}

// Function to check if a queen can be safely placed at board[row][col]
bool isSafe(const vector<vector<int>> &board, int row, int col)
{
    int i, j;

    // Check this column on upper rows
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true; // Safe position
}

// Recursive function to solve N-Queens using backtracking
bool solveNQueens(vector<vector<int>> &board, int row)
{
    // Base case: If all queens are placed
    if (row >= N)
        return true;

    // Try placing queen in each column of current row
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1; // Place queen

            // Recur to place rest of the queens
            if (solveNQueens(board, row + 1))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }

    // If no place is possible in this row
    return false;
}

int main()
{
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0))
    {
        cout << "One possible solution to the 8-Queens Problem:\n\n";
        printBoard(board);
    }
    else
    {
        cout << "No solution exists.\n";
    }

    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

#define N 8 // size of chess board

void printBoard(const vector<vector<int>> &board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; i < N; j++)
        {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << "\n";
}

bool isSafe(const vector<vector<int>> &board, int row, int col)
{
    int i, j;

    // check columns on upper rows
    for (i = 0; i < row; i++)
    {
        if (board[i][col])
        {
            return false;
        }
    }
    // upper left-diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    // check for upper right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

bool solveNQueen(vector<vector<int>> &board, int row)
{
    // base case: If all queens are placed
    if (row >= N)
    {
        return true;
    }

    // place queens in each column of row
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1; // place queen

            // recur to place the rest of the queens
            if (solveNQueen(board, row + 1))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueen(board, 0))
    {
        cout << "One possible solution to the 8-Queens Problem is as follows:\n\n";
        printBoard(board);
    }
    else
    {
        cout << "No solution found";
    }
}

// vector<vector<int>> board(N, vector<int>(N, 0))
// vector<vector<int>> board(N, vector<int>(N, 0))
*/