#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> ratings(n);
        string like;
        
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> ratings[i];
            sum += ratings[i];
        }

        cin >> like;

        int z = 0;

        vector<pair<int, int>> dis;
        vector<pair<int, int>> lik;

        for (int i = 0; i < n; i++) {
            if (like[i] == '0') {
                z++;
                dis.push_back({ratings[i], i});
            }
            else {
                lik.push_back({ratings[i], i});
            }
        }

        sort(dis.begin(), dis.end());
        sort(lik.begin(), lik.end());

        vector<int> ans(n);

        for (int i = 0; i < dis.size(); i++) {
            ans[dis[i].second] = i + 1;
        }

        for (int i = 0; i < lik.size(); i++) {
            ans[lik[i].second] = i + z + 1;
        }

        for (int i : ans) {
            cout << i << " ";
        }

        cout << endl;
    }
}