#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 5) {
            cout << "2 4" << endl;
            continue;
        }

        cout << 2 << " " << (n - 1) / 2 << endl;
    }
}