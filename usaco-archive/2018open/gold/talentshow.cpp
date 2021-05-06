#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("talent.in", "r", stdin); freopen("talent.out", "w", stdout);
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> cows;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        cows.push_back({a, b});
    }

    sort(cows.begin(), cows.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return (a.second * 1.0 / a.first) > (b.second * 1.0 / b.first);
    });

    int totalw = 0;
    int totalt = 0;

    for (int i = 0; i < n; i++) {
        totalw += cows[i].first;
        totalt += cows[i].second;

        if (totalw >= w) {
            break;
        }
    }

    cout << floor(totalt * 1000.0 / totalw) << endl;
}