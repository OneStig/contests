#include <bits/stdc++.h>

using namespace std;

set<int> nobles[200001];

int main()
{
    int n, m;
    cin >> n >> m;

    int bigbois = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        nobles[u].insert(v);
        nobles[v].insert(u);

    }

    for (int i = 1; i <= n; i++) {
        if (nobles[i].empty()) {
            bigbois++;

        }
        else if (*nobles[i].rbegin() < i) {
            bigbois++;
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int t, u, v;
        cin >> t;

        if (t == 1) {
            cin >> u >> v;

            bool un = 0, vn = 0;

            if (nobles[u].empty() || *nobles[u].rbegin() < u) {
                un = 1;
            }

            if (nobles[v].empty() || *nobles[v].rbegin() < v) {
                vn = 1;
            }

            nobles[u].insert(v);
            nobles[v].insert(u);

            if (un == 1 && *nobles[u].rbegin() >= u) {
                bigbois--;
            }

            if (vn == 1 && *nobles[v].rbegin() >= v) {
                bigbois--;
            }
        }
        else if (t == 2) {
            cin >> u >> v;

            bool un = *nobles[u].rbegin() < u, vn = *nobles[v].rbegin() < v;


            nobles[u].erase(v);
            nobles[v].erase(u);

            if (un == 0 && (nobles[u].empty() || *nobles[u].rbegin() < u)) {
                bigbois++;
            }

            if (vn == 0 && (nobles[v].empty() || *nobles[v].rbegin() < v)) {
                bigbois++;
            }
        }
        else if (t == 3) {
            cout << bigbois << endl;
        }
    }
}