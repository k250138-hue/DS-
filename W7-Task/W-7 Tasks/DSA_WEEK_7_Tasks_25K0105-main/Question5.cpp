#include <iostream>

using namespace std;

const int N = 16;

long long totalSolutions = 0;
bool cols[N] = {false};
bool diag1[32] = {false};
bool diag2[32] = {false};

void solveFlags(int row) {
    if (row == N) {
        totalSolutions++;
        return;
    }

    for (int col = 0; col < N; col++) {
        int d1 = row - col + N - 1;
        int d2 = row + col;

        if (!cols[col] && !diag1[d1] && !diag2[d2]) {
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            solveFlags(row + 1);

            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
}

int main() {
    cout << "Calculating configurations for 16x16 grid " << endl;

    solveFlags(0);

    cout << "Max flags: " << N << endl;
    cout << "Total configurations: " << totalSolutions << endl;

    return 0;
}