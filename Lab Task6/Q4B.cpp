
#include <iostream>
using namespace std;

void printSecond(int n, int sum);

void printFirst(int n, int sum)
{
    if (n > 7)
        return;

    sum = sum + n;
    cout << sum << " ";

    printSecond(n + 1, sum);
}

void printSecond(int n, int sum)
{
    if (n > 7)
        return;

    sum = sum + n;
    cout << sum << " ";

    printFirst(n + 1, sum);
}

int main()
{
    printFirst(1, 0);

    return 0;
}
