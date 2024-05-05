#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 1) // odd
        {
            if (n == 3)
            {
                cout << "NO";
            } else {
                cout << "YES\n";
                int positive = (n/2) - 1;
                int negative = -(n/2);

                for (int i{}; i < n/2; ++i)
                {
                    cout << positive << " " << negative << " ";
                }
                cout << positive;
            }
            cout << '\n';
        } else {
            cout << "YES\n";
            for (int i{}; i < n/2; ++i)
            {
                cout << "1 -1 ";
            }
            cout << '\n';
        }
    }
}
