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

typedef unsigned short st;

int m;
string turn;
int n;
vector<vector<int>> moves;
map<string, int> w;
vector<string> ct;

unordered_map<st, ld> cache;

ld check(st cur) {
    if (cache.contains(cur)) return cache[cur];

    bool oppturn = cur & (1 << 15);
    char myl = turn[0];
    ld bestwin{};

    for (auto& mv : moves) {
        for (int k = 1; k <= sz(mv); k++) {
            ld curwin{};

            ld prob = 1;
            for (int i = 0; i < k; i++) {

                for (int nxt : mv) {

                }
            }

            bestwin = max(bestwin, curwin);
        }
    }

    cache[cur] = bestwin;
    return bestwin;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> turn;
    ct = vector<string>(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        w[s] = i;
    }

    for (auto& x : ct) cin >> x;

    cin >> m;
    moves = vector<vector<int>>(m);

    for (auto& x : moves) {
        int hi;
        cin >> hi;
        x = vector<int>(hi);
        for (auto& y : x) {
            string sty;
            cin >> sty;
            cin >> w[sty];
        }
    }

    ld ans = check(0);
    cout << ans << '\n';
}
