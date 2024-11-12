#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid;
    cin.ignore(100,'\n');
    for (int i = 0; i < n; i++){
        vector<int> g;
        for (int j = 0; j < m; j++){
            char c;
            cin.get(c);
            if (c == '0') {
                g.push_back(1);
            }
            else {
                g.push_back(0);
            }
        }
        grid.push_back(g);
        cin.ignore(1000,'\n');
    }
    vector<pair<int,int>> ans;
    for (int x = 1; x < n-1; x++) {
        for (int y = 1; y < m-1; y++) {
            bool good = true;
            if (grid[x][y] == 0) {
                continue;
            }
            for (int dx = -1 ; dx < 2; dx++) {
                for (int dy = -1; dy < 2; dy++) {
                    if (dx == 0 and dy == 0) {
                        continue;
                    }
                    if (grid[x+dx][y+dy] == 1) {
                        good = false;
                    }
                }
            }
            if (good) {
                ans.push_back({x,y});
            }
        }
    }
    if (ans.size() == 0) {
        cout << "Oh no!\n";
    }
    if (ans.size() == 1) {
        cout << ans[0].first + 1 << " " << ans[0].second + 1 << "\n";
    }
    if (ans.size() > 1) {
        cout << "Oh no! " << ans.size() << " locations\n";
    }
}