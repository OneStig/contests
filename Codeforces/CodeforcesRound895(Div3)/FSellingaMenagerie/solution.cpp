#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> par(n + 1), val(n + 1), child(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> par[i];
            child[par[i]]++;
        }

        queue<int> trees;
        for (int i = 1; i <= n; i++) {
            cin >> val[i];
            if (child[i] == 0) {
                trees.push(i);
            }
        }

        set<int> seen;
        vector<int> ans;
        while (sz(trees)) {
            int cur = trees.front();
            trees.pop();
            seen.insert(cur);
            ans.push_back(cur);

            if (--child[par[cur]] == 0) {
                trees.push(par[cur]);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!seen.contains(i)) {
                seen.insert(i);
                vector<int> path = {i};
                int cur = par[i];
                int idx{}, mn = val[i];
                while (cur != i) {
                    seen.insert(cur);
                    if (val[cur] < mn) {
                        mn = val[cur];
                        idx = sz(path);
                    }
                    path.push_back(cur);
                    cur = par[cur];
                }

                idx = (idx + 1) % sz(path);
                ans.push_back(path[idx]);

                for (int j = (idx + 1) % sz(path); j != idx; j = (j + 1) % sz(path)) {
                    ans.push_back(path[j]);
                }
            }
        }

        for (int& x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
