
#include <iostream>
using namespace std;

void printSecond(int n);

void printFirst(int n)
{
    if (n > 15)
    {
        return;
    }

    cout << n << " ";

    printSecond(n + 1);
}

void printSecond(int n)
{
    if (n > 15)
    {
        return;
    }

    cout << n << " ";

    printFirst(n + 1);
}

int main()
{
    printFirst(1);

    return 0;
}
