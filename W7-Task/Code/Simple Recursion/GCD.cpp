#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    // Base case
    if (b == 0)
        return a;

    // Recursive case
    return gcd(b, a % b);
}

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD = " << gcd(a, b);

    return 0;
}