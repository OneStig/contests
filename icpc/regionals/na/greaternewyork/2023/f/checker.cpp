#include <bits/stdc++.h>

using namespace std;

int main() {
    int nt, ns, r;
    cin >> nt >> ns >> r;
    int rx = -9999, ry = -9999;

    map<int, set<int>> forest;

    int total{};
    for (int i = 0; i < nt; i++) {
        int x, y;
        cin >> x >> y;

        if (abs(rx - x) + abs(ry - y) <= r) {
            total++;
            forest[x].insert(y);
        }
    }

    cout << total << '\n';

    for (int i = 0; i < ns; i++) {
        int x, y;
        cin >> x >> y;
        x += rx, y += ry;
        if (!forest[x].contains(y)) {
            cout << x << ' ' << y << '\n';
        }
        forest[x].erase(y);
    }

    cout << "remaining\n";

    for (auto [a, b] : forest) {
        if (!b.empty()) {
            for (auto it = b.begin(); it != b.end(); it++) {
                cout << a << ' ' << *it << '\n';
            }
        }
    }
}
