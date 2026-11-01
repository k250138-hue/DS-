#include <iostream>
using namespace std;

int fun(int n)
{
    if (n > 5)
        return n;

    cout << "Before: " << n << endl;

    int x = fun(n + 1);

    cout << "After: " << n << endl;

    return fun(x);
}

int main()
{
    cout << fun(3);
}