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

const int MAX_B = 20;

bool dfs(int start, unordered_set<int>& lvis, unordered_set<int>& visited, unordered_map<int, vector<int>>& adj) {
    if (lvis.count(start)) {
        return 1;
    }

    if (visited.count(start)) {
        return 0;
    }

    visited.insert(start);
    

    lvis.insert(start);

    for (int& nb : adj[start]) {
        if (dfs(nb, lvis, visited, adj)) {
            return 1;
        }
    }

    lvis.erase(start);

    return 0;
};

int toint(bool row, int num, int bit) {
    return num * MAX_B * 2 + bit * 2 + row;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> A(n, vector<int>(m)), B(n, vector<int>(m));
    for (auto& x : A) for (int& y : x) cin >> y;
    for (auto& x : B) for (int& y : x) cin >> y;

    unordered_map<int, vector<int>> adj;
    
    for (int b = 0; b < MAX_B; b++) {
        int mask = 1 << b;

        for (int r = 0; r < n; r++) {
            int currow = toint(1, r, b);

            for (int c = 0; c < m; c++) {
                int curcol = toint(0, c, b);

                if (B[r][c] & mask) {
                    adj[currow].push_back(curcol);
                }
                else {
                    adj[curcol].push_back(currow);
                }
            }
        }
    }

    unordered_set<int> visited;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            for (int b = 0; b < MAX_B; b++) {
                bool abit = A[r][c] & (1 << b);
                bool bbit = B[r][c] & (1 << b);

                if (abit != bbit) {
                    int needed = toint(abit, (abit ? r : c), b);
                    unordered_set<int> lvis;
                    if (dfs(needed, lvis, visited, adj)) {
                        cout << "No\n";
                        return;
                    }

                    for (auto x : lvis) {
                        visited.insert(x);
                    }
                }
            }
        }
    }

    cout << "Yes\n";
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
