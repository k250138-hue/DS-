#include <iostream>
using namespace std;

bool isSafe(int maze[][4], int row, int col, int N)
{

    return (row >= 0 && row < N && col >= 0 && col < N && maze[row][col] == 1);
}

bool solveMaze(int maze[][4], int x, int y, int N, int sol[][4], int destX, int destY)
{

    if (x == destX && y == destY)

    {

        sol[x][y] = 1;

        return true;
    }

    if (isSafe(maze, x, y, N))
    {

        sol[x][y] = 1;

        // Try moving down, right, up, left according to possible destinations

        if (destY > y && solveMaze(maze, x, y + 1, N, sol, destX, destY))

        { // Right

            return true;
        }

        if (destX > x && solveMaze(maze, x + 1, y, N, sol, destX, destY))

        { // Down

            return true;
        }

        if (destY < y && y > 0 && solveMaze(maze, x, y - 1, N, sol, destX, destY))

        { // Left

            return true;
        }

        if (destX < x && x > 0 && solveMaze(maze, x - 1, y, N, sol, destX, destY))

        { // Up

            return true;
        }

        sol[x][y] = 0; // Backtrack
    }

    return false;
}

int main()
{

    int N = 4;

    int maze[N][4] = {

        {1, 0, 0, 0},

        {1, 1, 0, 1},

        {1, 1, 0, 0},

        {0, 1, 1, 1}

    };

    int sol[N][4] = {0};

    // Get user input for starting position

    int startX, startY;

    cout << "Enter rat's starting row (0 - " << N - 1 << "): ";

    cin >> startX;

    cout << "Enter rat's starting column (0 - " << N - 1 << "): ";

    cin >> startY;

    // Get user input for destination position

    int destX, destY;

    cout << "Enter destination row (0 - " << N - 1 << "): ";

    cin >> destX;

    cout << "Enter destination column (0 - " << N - 1 << "): ";

    cin >> destY;

    if (solveMaze(maze, startX, startY, N, sol, destX, destY))
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