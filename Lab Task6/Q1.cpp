
#include <iostream>
using namespace std;

void permutation(string str, int index, int n)
{
    if (index == n)
    {
        cout << str << " ";
        return;
    }

    for (int i = index; i < n; i++)
    {
        char temp = str[index];
        str[index] = str[i];
        str[i] = temp;

        permutation(str, index + 1, n);

        temp = str[index];
        str[index] = str[i];
        str[i] = temp;
    }
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    if (n < 1 || n > 26)
    {
        cout << "Enter n between 1 and 26." << endl;
        return 0;
    }

    string str = "";

    for (int i = 0; i < n; i++)
    {
        str = str + char('a' + i);
    }
    
    permutation(str, 0, n);

    return 0;
}
