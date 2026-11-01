
#include <iostream>
using namespace std;

void subsequence(string str, int n, int index, string ans)
{
    if (index == n)
    {
        cout << "{" << ans << "}" << endl;
        return;
    }

    // Exclude the current character
    subsequence(str, n, index + 1, ans);

    // Include the current character
    ans = ans + str[index];

    subsequence(str, n, index + 1, ans);
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    string ans = "";

    cout << "Subsequences:" << endl;

    subsequence(str, str.length(), 0, ans);

    return 0;
}
