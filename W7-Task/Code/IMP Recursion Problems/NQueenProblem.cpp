#include <iostream>
using namespace std;

// Can we put a queen at (row, col)?
// We only look at squares ABOVE this row, because queens are placed
// from the top row to the bottom row (rows below are still empty).
bool isSafe(int **board, int n, int row, int col)
{
    // 1. Same column (going up)
    for (int r = 0; r < row; r++)
    {
        if (board[r][col] == 1)
        {
            return false;
        }
    }

    // 2. Diagonal going up-left
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--)
    {
        if (board[r][c] == 1)
        {
            return false;
        }
    }

    // 3. Diagonal going up-right
    for (int r = row - 1, c = col + 1; r >= 0 && c < n; r--, c++)
    {
        if (board[r][c] == 1)
        {
            return false;
        }
    }

    return true; // nothing attacks this square
}

// Place queens in row "row", then row + 1, ... until all n rows are done.
bool nQueen(int **board, int n, int row)
{
    // Base case: every row already has a queen -> solved!
    if (row == n)
    {
        return true;
    }

    // Try every column of this row, from left to right
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, n, row, col))
        {
            board[row][col] = 1; // place the queen

            if (nQueen(board, n, row + 1)) // try to fill the next row
            {
                return true; // it worked, stop here
            }

            board[row][col] = 0; // it did not work: remove the queen (backtrack)
        }
    }

    return false; // no column worked in this row
}

int main()
{
    int n;
    cout << "Enter N (board size and number of queens): ";
    cin >> n;

    // Create an n x n board and fill it with 0
    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if (nQueen(board, n, 0))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}