#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        if (x == y || y % x == 0) {
            cout << x << endl;
            continue;
        }

        if (x > y) {
            cout << x + y << endl;
            continue;
        }

        if (y <= x * 2) {
            cout << (y + x) / 2 << endl;
            continue;
        }

        long long k = y - (y % x);
        cout << (y + k) / 2;
    }
}