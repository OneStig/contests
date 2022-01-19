#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if ((n % 2 == 0 && n / 2 < k )|| (n % 2 == 1 && n / 2 + 1 < k)) {
            cout << -1 << endl;
            continue;
        } 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (k > 0 && i == j && i % 2 == 0) {
                    cout << 'R';
                    k--;
                }
                else {
                    cout << '.';
                }
            }

            cout << endl;
        }
    }
}