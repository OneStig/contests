#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        bool zf = 0;
        bool 

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 0) {
                zf = 1;
                break;
            }
        }

        if (zf) {
            cout << "YES" << endl;
            continue;
        }

        
    }
}