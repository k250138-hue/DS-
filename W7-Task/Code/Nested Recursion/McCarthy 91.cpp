#include <iostream>
using namespace std;

int M(int n)
{
    if (n > 100)
        return n - 10;

    return M(M(n + 11));
}

int main()
{
    cout << M(100) << endl;
    cout << M(99) << endl;
    cout << M(50) << endl;
    cout << M(101) << endl;
    cout << M(110) << endl;

    return 0;
}