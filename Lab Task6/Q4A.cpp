
#include <iostream>
using namespace std;

void sequence(int n, int sum, int count)
{
    if (count > n)
        return;

    sum = sum + count;
    cout << sum << " ";

    sequence(n, sum, count + 1);
}

int main()
{
    int n = 7;
    sequence(n, 0, 1);

    return 0;
}
