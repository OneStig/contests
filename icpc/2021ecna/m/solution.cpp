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

int m, n, k;
const int INF = 1e9;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;
    vector<vector<char>> g(m, vector<char>(n));

    vector<string> dict(k);
    set<string> hasword;
    map<string, vector<string>> pfx;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    for (string& x : dict) {
        cin >> x;
        hasword.insert(x);
        for (int i = 0; i < sz(x); i++) {
            pfx[x.substr(0, i)].push_back(x);
        }
    }

    vector<map<string, int>> last(n);
    for (auto& x : last) {
        x[""] = 0;
    }

    for (int i = 0; i < m; i++) {
        vector<map<string, int>> curleft(n), curright(n);

        for (int start = 0; start < n; start++) {
            for (auto [cont, len] : last[start]) {
                set<string> avail = {cont};
                for (int end = start; end < n; end++) {
                    if (avail.empty()) break;
                    int score = len + end - start + 1;
                    set<string> nxt;

                    for (string cand : avail) {
                        cand += g[i][end];
                        if (pfx.contains(cand)) {
                            if (!curright[end].contains(cand) || curright[end][cand] > score) {
                                curright[end][cand] = score;
                                nxt.insert(cand);
                            }
                        }

                        if (hasword.contains(cand)) {
                            if (!curright[end].contains("") || curright[end][""] > score) {
                                curright[end][""] = score;
                                nxt.insert("");
                            }
                        }
                    }

                    avail = nxt;
                }

                set<string> avail2 = {cont};
                for (int end = start; end >= 0; end--) {
                    if (avail2.empty()) break;
                    int score = len + start - end + 1;
                    set<string> nxt;

                    for (string cand : avail2) {
                        cand += g[i][end];
                        if (pfx.contains(cand)) {
                            if (!curleft[end].contains(cand) || curleft[end][cand] > score) {
                                curleft[end][cand] = score;
                                nxt.insert(cand);
                            }
                        }

                        if (hasword.contains(cand)) {
                            if (!curleft[end].contains("") || curleft[end][""] > score) {
                                curleft[end][""] = score;
                                nxt.insert("");
                            }
                        }
                    }

                    avail2 = nxt;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            // dbg(i, curleft[i]);
            for (auto [x, y] : curright[i]) {
                if (!curleft[i].contains(x) || curleft[i][x] > y) {
                    curleft[i][x] = y;
                }
            }

            // dbg(i, curleft[i]);
        }

        last = curleft;


        // for (auto& x : last) {
        //     dbg(x);
        // }
        // dbg("=======================");
    }

    int ans = INF;
    for (auto& x : last) {
        if (x.contains("")) {
            ans = min(ans, x[""]);
        }
    }

    cout << (ans == INF ? "impossible" : to_string(ans)) << '\n';
}
