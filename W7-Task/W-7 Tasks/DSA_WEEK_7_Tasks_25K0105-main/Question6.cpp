#include <iostream>
using namespace std;

const int N = 6;

char grid[N][N] = {
    {'D', 'S', 'S', 'F', 'D', 'F'},
    {'S', 'S', 'S', 'F', 'S', 'D'},
    {'S', 'D', 'S', 'S', 'S', 'F'},
    {'F', 'S', 'F', 'S', 'S', 'F'},
    {'S', 'S', 'S', 'D', 'S', 'F'},
    {'S', 'F', 'S', 'S', 'S', 'H'}
};

bool visited[N][N] = {false};
int bestWindCount = 1000;
int bestPath[N][N] = {0};
int currentPath[N][N] = {0};

void findPath(int x, int y, int windCount) {
    if (x < 0 || x >= N || y < 0 || y >= N) return;
    if (grid[x][y] == 'F' || visited[x][y]) return;
    if (windCount >= bestWindCount) return;

    if (grid[x][y] == 'H') {
        if (windCount < bestWindCount) {
            bestWindCount = windCount;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    bestPath[i][j] = currentPath[i][j];
                }
            }
            bestPath[x][y] = 1;
        }
        return;
    }

    visited[x][y] = true;
    currentPath[x][y] = 1;

    int nextWind = windCount + (grid[x][y] == 'D' ? 1 : 0);

    findPath(x + 1, y, nextWind);
    findPath(x, y + 1, nextWind);
    findPath(x - 1, y, nextWind);
    findPath(x, y - 1, nextWind);

    visited[x][y] = false;
    currentPath[x][y] = 0;
}

int main() {
    findPath(0, 0, 0);

    cout << "Min D cells: " << bestWindCount << endl;
    cout << "Path grid:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << bestPath[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}