#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string b;
        cin >> b;

        int z = 0;
        int r = 0;

        for (int i = 0; i < b.length(); i++) {
            if (i != 0 && b[i] == '0' && b[i - 1] == '1' && z > 0) {
                r = 1;
                break;
            }

            if (b[i] == '0') {
                z++;
            }
        }

        if (r) {
            cout << 2 << endl;
        }
        else if (z == 0) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }   
}