#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int W, H, x1, y1, x2, y2;
        int tw, th;

        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> tw >> th;

        if (tw - x1 <= 0 || th - y1 <= 0 ||
            x2 - (W - tw) <= 0 || H - (H - th) <= 0) {
            cout << 0 << endl;
            continue;
        }

        int sol = INT_MAX;

        if (x2 - x1 + tw <= W ) {
            sol = min(tw - x1, x2 - (W - tw));
        }

        if (y2 - y1 + th <= H) {
            sol = min(sol, min(th - y1, y2 - (H - th)));
        }

        if (sol == INT_MAX) {
            cout << -1 << endl;
            continue;
        }

        cout << sol << endl;

    }
}