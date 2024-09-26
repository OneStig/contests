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
const int INF = 1e12;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> fcounts(n), ccount(n);
    vector<vector<int>> lift(n, vector<int>(MAX_B));
    vector<vector<int>> agg(n, vector<int>(MAX_B));

    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j += i) {
            fcounts[j]++;
        }

        int par = (i + fcounts[i]) % n;
        lift[i][0] = par;
        agg[i][0] = par;
        ccount[par]++;
    }

    for (int b = 1; b < MAX_B; b++) {
        for (int i = 1; i < n; i++) {
            lift[i][b] = lift[lift[i][b - 1]][b - 1];
            agg[i][b] = agg[i][b - 1] + agg[lift[i][b - 1]][b - 1];
        }
    }

    vector<int> mxlen(n, -1), dist(n, -1);

    for (int i = 0; i < n; i++) {
        if (ccount[i] == 0) {
            vector<int> path;

            int cur = i, ply = 0;
            while (mxlen[cur] == -1 && dist[cur] == -1) {
                dist[cur] = ply++;
                path.push_back(cur);
                cur = lift[cur][0];
            }

            bool loop = 1;
            if (mxlen[cur] == -1) {
                mxlen[cur] = ply - dist[cur] - 1;
            }
            else {
                loop = 0;
            }

            for (int i = sz(path) - 1; i >= 0; i--) {
                int a = path[i];

                if (a == cur) {
                    loop = 0;
                    continue;
                }

                if (loop) {
                    mxlen[a] = mxlen[cur];
                }
                else {
                    mxlen[a] = mxlen[lift[a][0]] + 1;
                }
            }
        }
    }

    auto up = [&](int s, int len) -> int {
        if (len > mxlen[s]) return -1;
        int sum = s;
        for (int b = MAX_B - 1; b >= 0; b--) {
            if (((1 << b) & len) != 0) {
                sum += agg[s][b];
                s = lift[s][b];
            }
        }

        return sum;
    };

    int best = -1, bsum = INF;
    for (int i = 0; i < n; i++) {
        int cur = up(i, k - 1);
        if (cur != -1 && cur < bsum) {
            bsum = cur;
            best = i;
        }
    }

    if (best == -1) {
        cout << "-1\n";
    }
    else {
        cout << best;
        for (int i = 1; i < k; i++) {
            best = lift[best][0];
            cout << ' ' << best;
        }

        cout << '\n';
    }
}
