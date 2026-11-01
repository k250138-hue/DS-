#include <iostream>
using namespace std;

int fun(int n)
{
    if (n > 0)
    {
        cout << n << " ";

        return fun(fun(n - 1));
    }

    return 0;
}

int main()
{
    fun(3);

    return 0;
}