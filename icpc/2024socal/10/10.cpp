#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
    cin.tie(0)->sync_with_stdio();
    int n;
    cin >> n;
    while (n--) {
        int a1,b1;
        int a2,b2;
        int a3,b3;
        int a4,b4;
        bool good = true;
        cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;
        if ((b2 - b1) * (a3 - a1) == (b3 - b1) * (a2 - a1)) {
            if ((b2 - b1) * (a4 - a1) == (b4 - b1) * (a2 - a1)) {
                good = false;
            }
        }
        if (good) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}