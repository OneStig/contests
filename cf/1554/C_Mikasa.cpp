#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        if (m < n) {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < max(n, m); i++) {
            if ((n ^ i) > m) {
                cout << i << endl;
                break;
            }
        }
    }
}