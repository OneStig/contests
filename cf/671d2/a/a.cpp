#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    string num;
    cin >> num;

    if (n == 1) {
        if ((num[0] - '0') % 2 == 0) {
            cout << 2 << endl;
            return;
        }

        cout << 1 << endl;
        return;
    }

    int e, o = 0;
    if (n % 2 == 0)
    { // breach controls digit
        for (int i = 1; i < num.length(); i += 2)
        {
            if ((num[i] - '0') % 2 == 0) {
                cout << 2 << endl;
                return;
            }
        }

        cout << 1 << endl;
        return;
    }

    for (int i = 0; i < num.length(); i += 2)  {
        if ((num[i] - '0') % 2 != 0) {
            cout << 1 << endl;
            return;
        }
    }

    cout << 2 << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) // raze marks 1, breach 2
    {
        solve();
    }
}