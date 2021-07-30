#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            cout << "a" << endl;
            continue;
        }

        string ans = "";

        for (int i = 0; i < n / 2; i++) {
            ans += "a";
        }

        if (n % 2 == 1) {
            ans += "bc";
        }
        else {
            ans += "b";
        }

        for (int i = 0; i < n / 2 - 1; i++) {
            ans += "a";
        }

        cout << ans << endl;
    }
}