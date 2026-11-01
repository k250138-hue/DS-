#include <iostream>
using namespace std;

bool isSafe(int maze[][4], int row, int col, int N)
{

    // Check if cell is within maze boundaries and has a valid path

    return (row >= 0 && row < N && col >= 0 &&

            col < N && maze[row][col] == 1);
}

bool solveMaze(int maze[][4], int x, int y, int N, int sol[][4])

{

    // If rat reaches the destination (bottom right corner)

    if (x == N - 1 && y == N - 1)
    {

        sol[x][y] = 1;

        return true;
    }

    // If current cell is valid, mark it in the solution matrix

    if (isSafe(maze, x, y, N))
    {

        sol[x][y] = 1;

        // Recursively try all possible moves (down, right, up, left)

        if (solveMaze(maze, x + 1, y, N, sol))

        { // Down

            return true;
        }

        if (solveMaze(maze, x, y + 1, N, sol))

        {

            // Right

            return true;
        }

        if (x > 0 && solveMaze(maze, x - 1, y, N, sol))

        {

            // Up (avoid going out of bounds)

            return true;
        }

        if (y > 0 && solveMaze(maze, x, y - 1, N, sol))

        {

            // Left (avoid going out of bounds)

            return true;
        }

        // Backtrack if no valid move is found

        sol[x][y] = 0;
    }

    return false; // No solution found
}

int main()

{

    int N = 4; // Size of the maze

    int maze[N][4] =

        {

            {1, 0, 0, 0},

            {1, 1, 0, 1},

            {1, 1, 0, 0},

            {0, 1, 1, 1}

    };

    // Solution matrix to store the path

    int sol[N][4] = {0};

    if (solveMaze(maze, 0, 0, N, sol))

    {

        cout << "Solution found!\n";

        for (int i = 0; i < N; i++)
        {

            for (int j = 0; j < N; j++)
            {

                cout << sol[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {

        cout << "No solution exists.\n";
    }

    return 0;
}