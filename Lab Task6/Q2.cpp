
#include <iostream>
using namespace std;

bool isSafe(int maze[][4], int row, int col, int N)
{
    return (row >= 0 && row < N &&
            col >= 0 && col < N &&
            maze[row][col] == 1);
}

int countPaths(int maze[][4], int row, int col, int N)
{
    if (row == N - 1 && col == N - 1)
    {
        return 1;
    }

    if (!isSafe(maze, row, col, N))
    {
        return 0;
    }

    int down = countPaths(maze, row + 1, col, N);

    int right = countPaths(maze, row, col + 1, N);

    return down + right;
}

int main()
{
    int N = 4;

    int maze[4][4] =
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int total = countPaths(maze, 0, 0, N);

    cout << "Number of paths: " << total << endl;

    return 0;
}



// int countPaths(int maze[][4], int row, int col, int N, int sol[][4])
// {
//     if (row == N - 1 && col == N - 1)
//     {
//         return 1;
//     }

//     if (!isSafe(maze, row, col, N) || sol[row][col] == 1)
//     {
//         return 0;
//     }

//     sol[row][col] = 1;

//     int down = countPaths(maze, row + 1, col, N, sol);
//     int right = countPaths(maze, row, col + 1, N, sol);
//     int up = countPaths(maze, row - 1, col, N, sol);
//     int left = countPaths(maze, row, col - 1, N, sol);

//     sol[row][col] = 0;

//     return down + right + up + left;
// }