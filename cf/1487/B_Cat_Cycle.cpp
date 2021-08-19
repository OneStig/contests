#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (n % 2 == 1) {
            k += (k - 1) / (n / 2);
        }

        k %= n;
        cout << (k == 0 ? n : k) << endl;
    }
}