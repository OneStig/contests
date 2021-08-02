#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n <= 6) {
            cout << 15 << endl;
            continue;
        }

        if (n % 2 == 1) {
            n++;
        }

        cout << (long long)(n * 2.5) << endl;
    }
}