#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int INF = 1e9;

uci main() {
    cin.tie(0)->sync_with_stdio();

    int n;
    cin >> n;
    vector<string> a(n);

    for (string& x : a) cin >> x;
    sort(all(a));

    int ans = INF;
    vector<string> bests;

    do {
        vector<string> cur = vector<string>();
        cur.push_back(a[0]);

        for (int i = 1; i < n; i++) {
            vector<string> nextcur = vector<string>();

            string mg = a[i];
            for (string ccur : cur) {
                for (int k = sz(mg); k > 0; k--) {
                    string mid = mg.substr(0, k);
                    if (sz(ccur) >= k && ccur.substr(sz(ccur) - k, k) == mid) {
                        string nxt = ccur;
                        if (k < sz(mg)) {
                            nxt += mg.substr(k, sz(mg) - k);
                        }

                        nextcur.push_back(nxt);
                    }

                    string mid2 = mg.substr(sz(mg) - k, k);
                    if (sz(ccur) >= k && ccur.substr(0, k) == mid2) {
                        string nxt = mg;
                        if (sz(ccur) > k) {
                            nxt += ccur.substr(k, sz(ccur) - k);
                        }

                        nextcur.push_back(nxt);
                    }
                }
            }

            swap(cur, nextcur);
        }

        for (string& x : cur) {
            if (sz(x) == ans) {
                bests.push_back(x);
            }
            else if (sz(x) < ans) {
                ans = sz(x);
                bests = vector<string>();
                bests.push_back(x);
            }
        }

    } while(next_permutation(all(a)));

    if (ans == INF) {
        cout << -1 << '\n';
    }
    else {
        sort(all(bests));
        cout << bests[0] << '\n';
    }
}