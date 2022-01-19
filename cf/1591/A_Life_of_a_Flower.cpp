#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int last = -1;
        int h = 1;

        for (int i = 0; i < n; i++) {
            int cur;
            cin >> cur;

            if (h == -1) {
                continue;
            }

            if (cur == 0 && last == 0) {
                h = -1;
            } if (cur == 1) {
                if (last == 1) {
                    h += 5;
                }
                else {
                    h++;
                }
            }

            last = cur;
        }

        cout << h << endl;
    }
}