#include <iostream>

using namespace std;

const int N = 5;

char grid[N][N] = {
    {'S', 'A', 'A', 'T', 'A'},
    {'A', 'T', 'A', 'A', 'G'},
    {'T', 'A', 'T', 'A', 'F'},
    {'A', 'A', 'A', 'T', 'G'},
    {'A', 'T', 'G', 'T', 'G'}
};

int squirrelPath[N][N] = {0};
int foxPath[N][N] = {0};

bool solveSquirrel(int x, int y, int collected, bool visited[N][N]) {
    if (collected == 7) return true;
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    if (grid[x][y] == 'T' || visited[x][y]) return false;

    visited[x][y] = true;
    squirrelPath[x][y] = 1;

    int found = (grid[x][y] == 'A') ? 1 : 0;

    if (solveSquirrel(x + 1, y, collected + found, visited)) return true;
    if (solveSquirrel(x, y + 1, collected + found, visited)) return true;
    if (solveSquirrel(x - 1, y, collected + found, visited)) return true;
    if (solveSquirrel(x, y - 1, collected + found, visited)) return true;

    visited[x][y] = false;
    squirrelPath[x][y] = 0;
    return false;
}

bool solveFox(int x, int y, int collected, bool visited[N][N]) {
    if (collected == 6) return true;
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    if (grid[x][y] == 'T' || visited[x][y]) return false;

    visited[x][y] = true;
    foxPath[x][y] = 1;

    int found = (grid[x][y] == 'G') ? 1 : 0;

    if (solveFox(x + 1, y, collected + found, visited)) return true;
    if (solveFox(x, y + 1, collected + found, visited)) return true;
    if (solveFox(x - 1, y, collected + found, visited)) return true;
    if (solveFox(x, y - 1, collected + found, visited)) return true;

    visited[x][y] = false;
    foxPath[x][y] = 0;
    return false;
}

int main() {
    bool squirrelVisited[N][N] = {false};
    bool foxVisited[N][N] = {false};

    solveSquirrel(0, 0, 0, squirrelVisited);
    solveFox(2, 4, 0, foxVisited);

    cout << "Squirrel Path:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << squirrelPath[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nFox Path:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << foxPath[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}