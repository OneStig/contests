#include <bits/stdc++.h>

using namespace std;

bool sortrev(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

bool altsort(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> sight(n * m);

        for (int i = 0; i < n * m; i++) {
            cin >> sight[i].first;
            sight[i].second = i;
        }

        sort(sight.begin(), sight.end(), sortrev);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int red = 0;

                for (int k = 0; k < j; k++) {

                    if (sight[i * m + k].second < sight[i * m + j].second) {
                        red++;
                    }
                }

                ans += red;
            }
        }

        cout << ans << endl;
    }
}