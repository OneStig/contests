#include <bits/stdc++.h>

using namespace std;

bool sortrev(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> sight(n * m);
        map<int, set<int>> pos;

        for (int i = 0; i < n * m; i++) {
            cin >> sight[i].first;
            sight[i].second = i;
            pos[sight[i].first].insert(i);
        }

        sort(sight.begin(), sight.end(), sortrev);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> row(m);

            for (int j = m - 1; j >= 0; j--) {
                row[j].first = *pos[sight[i * m + j].first].begin();

                // cout << row[j].first<< " ";
                pos[sight[i * m + j].first].erase(row[j].first);
                row[j].second = j;
            }

            sort(row.begin(), row.end());

            set<int> seated;

            for (int j = 0; j < m; j++) {
                
                seated.insert(row[j].second);

                ans += distance(seated.begin(), seated.find(row[j].second));
            }

            // cout << endl;
        }

        cout << ans << endl;
    }
}